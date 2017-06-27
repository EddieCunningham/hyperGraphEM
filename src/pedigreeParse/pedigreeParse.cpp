#include "/Users/Eddie/hyperGraphEM/src/pedigreeParse/pedigreeParser.h"


PedigreeParser::PedigreeParser(string filename): _filename(filename) {

    ifstream ifs(filename);
    string jsonBefore((istreambuf_iterator<char>(ifs)), (istreambuf_iterator<char>()));
    jsonBefore = jsonBefore.substr(1,jsonBefore.size()-2);
    boost::replace_all(jsonBefore,"\\\"","\"");
    cout << jsonBefore << endl;

    _doc.Parse(jsonBefore.c_str());

}

void PedigreeParser::printRawJSON() {
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    _doc.Accept(writer);
    cout << buffer.GetString() << endl;
}


void PedigreeParser::parseJSON(PedigreeAllocator& pedigreeAllocator) {
    
    int i = 0;
    for(auto& part : _doc.GetArray()) {
        if(i == 0) {
            continue;
        }

    }    
}
