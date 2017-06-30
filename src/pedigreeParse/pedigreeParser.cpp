#include "/Users/Eddie/hyperGraphEM/src/pedigreeParse/pedigreeParser.h"


PedigreeParser::PedigreeParser(string filename): _filename(filename) {

    ifstream ifs(filename);
    string jsonBefore((istreambuf_iterator<char>(ifs)), (istreambuf_iterator<char>()));
    jsonBefore = jsonBefore.substr(1,jsonBefore.size()-2);
    boost::replace_all(jsonBefore,"\\\"","\"");
    _doc.Parse(jsonBefore.c_str());

}

void PedigreeParser::printRawJSON() {
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    _doc.Accept(writer);
    cout << buffer.GetString() << endl;
}

void PedigreeParser::_addPerson(int Id, string jsonifiedData, PedigreeAllocator& pedigreeAllocator) {

    if(pedigreeAllocator.getPerson(Id) == nullptr) {

        Data* data = nullptr;
        if(jsonifiedData != "NOTHING") {
            data = pedigreeAllocator.allocateData(jsonifiedData);
        }
        Person* person = pedigreeAllocator.allocatePerson(Id,data);
    }
}

void PedigreeParser::_addFamily(int mateA_, int mateB_, const vector<int>& children) {

    int mateA = min(mateA_,mateB_);
    int mateB = max(mateA_,mateB_);
    string key = to_string(mateA)+"~"+to_string(mateB);
    if(_intFamilies.find(key) == _intFamilies.end()) {

        vector<int> sortedChildren = children;
        sort(sortedChildren.begin(),sortedChildren.end());
        _intFamilies[key] = sortedChildren;
    }
}

unordered_map<int,vector<int>> PedigreeParser::_parseMateKids(string mateKids) {

    unordered_map<int,vector<int>> ans;
    
    mateKids = mateKids.substr(1,mateKids.size()-2);
    vector<string> fams;
    boost::split(fams,mateKids,boost::is_any_of("~"));
    fams.pop_back();
    for(string& fam: fams) {
        string mate = fam.substr(0,fam.find(":"));
        string childrenStr = fam.substr(fam.find(":")+1);
        vector<string> children;
        boost::split(children,childrenStr,boost::is_any_of(","));
        children.pop_back();
        
        int mateInt = stoi(mate);
        vector<int> childrenInt = vector<int>();
        for(string& s: children) {
            int child = stoi(s);
            childrenInt.push_back(child);
        }
        ans[mateInt] = childrenInt;
    }
    return ans;
}

pair<int,int> PedigreeParser::_parseParentsString(string parentString) {

    pair<int,int> ans;
    vector<string> parents;
    boost::split(parents,parentString,boost::is_any_of("~"));
    ans.first = stoi(parents.at(0));
    ans.second = stoi(parents.at(1));
    return ans;
}


void PedigreeParser::_establishRelationships(int Id, string jsonifiedData, string mateKids, PedigreeAllocator& pedigreeAllocator) {

    _addPerson(Id,jsonifiedData,pedigreeAllocator);
    unordered_map<int,vector<int>> parsedMateKids = _parseMateKids(mateKids);

    for(pair<const int,vector<int>>& mateAndChildren: parsedMateKids) {

        int mate = mateAndChildren.first;
        if(mate < 0) {
            _addPerson(mate,"NOTHING",pedigreeAllocator);
        }
        const vector<int>& children = mateAndChildren.second;
        _addFamily(Id,mate,children);
    }
}

void PedigreeParser::_finalizeFamilies(PedigreeAllocator& pedigreeAllocator) {

    int count = 0;
    unordered_set<FamilyWrapper*> families = unordered_set<FamilyWrapper*>();

    for(pair<const string,vector<int>>& parentsAndChildren: _intFamilies) {

        string parentsString = parentsAndChildren.first;
        pair<int,int> parentsPair = _parseParentsString(parentsString);
        int parentAInt = parentsPair.first;
        int parentBInt = parentsPair.second;
        vector<int> childrenInt = parentsAndChildren.second;

        Person* parentA = pedigreeAllocator.getPerson(parentAInt);
        Person* parentB = pedigreeAllocator.getPerson(parentBInt);
        unordered_set<Person*> parents = unordered_set<Person*>({parentA,parentB});

        unordered_set<Person*> children = unordered_set<Person*>();
        for(int& childInt: childrenInt) {
            Person* child = pedigreeAllocator.getPerson(childInt);
            children.insert(child);
        }

        FamilyWrapper* family = pedigreeAllocator.allocateFamilyWrapper(count,parents,children);
        families.insert(family);
        ++count;
    }
    pedigreeAllocator.allocateDAH(families);
}

void PedigreeParser::_setDAH(DAH* dah) {
    _dah = dah;
}

void PedigreeParser::parseJSON(PedigreeAllocator& pedigreeAllocator) {
    
    int i = 0;
    for(auto& part : _doc.GetArray()) {
        if(i == 0) {
            ++i;
            continue;
        }
        
        int Id = stoi(part["Id"].GetString());  

        StringBuffer buffer;
        PrettyWriter<StringBuffer> writer(buffer);
        part.Accept(writer);      
        string jsonifiedData = buffer.GetString();

        string mateKids = part["mateKids"].GetString();

        _establishRelationships(Id,jsonifiedData,mateKids,pedigreeAllocator);
        ++i;
    }
    _finalizeFamilies(pedigreeAllocator);
    _setDAH(pedigreeAllocator.getDAH());
}

DAH* PedigreeParser::getDAH() {
    return _dah;
}
