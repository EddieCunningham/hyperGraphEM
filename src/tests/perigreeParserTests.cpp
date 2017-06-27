#include "/Users/Eddie/hyperGraphEM/src/pedigreeParse/pedigreeParser.h"
#include "/Users/Eddie/hyperGraphEM/src/tests/testMain.h"


class PedigreeParseTester {

    PedigreeParser _pedigreeParser;
    PedigreeAllocator _pedigreeAllocator;
    DAH* _dah;

    void _checkResult(const vector<Node*>& people, unordered_set<int>& expected);
    void _checkResult(const unordered_set<Node*>& people, unordered_set<int>& expected);
    void _checkResult(NodeIterator& returned, unordered_set<int> expected);

    Person* _getPerson(int id) {return _pedigreeAllocator.getPerson(id);}
public:
    PedigreeParseTester(string filename): _pedigreeParser(filename) {
        _pedigreeParser.parseJSON(_pedigreeAllocator);
        _dah = _pedigreeParser.getDAH();
    }

    void checkAllPeopleThere();
    void checkFamilyCreation();
    void checkFamilyCreationNot1084LN();
    void checkFamilyFunctionsNot1084LN();
    void checkIteratorFunctionsNot1084LN();
};

void PedigreeParseTester::_checkResult(const unordered_set<Node*>& people, unordered_set<int>& expected) {

    for(Node* person: people) {
        int id = person->id;
        if(expected.find(id) == expected.end()) {
            failWithMessage(__FILE__,__LINE__,"This person should not be here! ("+to_string(id)+")");
        }
        expected.erase(id);
    }
    if(expected.size() > 0) {
        failWithMessage(__FILE__,__LINE__,"Didn't iterate over all of the nodes!");
    }
}

void PedigreeParseTester::_checkResult(const vector<Node*>& people, unordered_set<int>& expected) {

    for(Node* person: people) {
        int id = person->id;
        if(expected.find(id) == expected.end()) {
            failWithMessage(__FILE__,__LINE__,"This person should not be here! ("+to_string(id)+")");
        }
        expected.erase(id);
    }
    if(expected.size() > 0) {
        failWithMessage(__FILE__,__LINE__,"Didn't iterate over all of the nodes!");
    }
}

void PedigreeParseTester::_checkResult(NodeIterator& returned, unordered_set<int> expected) {
    
    cout << "---------------" << endl;
    for(Node* node = returned.getCurrent(); node != nullptr; node = returned.next()) {
        int id = node->id;
        cout << "Person: " << id << endl;
        if(expected.find(id) == expected.end()) {
            failWithMessage(__FILE__,__LINE__,"This node should not be here! ("+to_string(id)+")");
        }
        expected.erase(id);
    }
    if(expected.size() > 0) {
        failWithMessage(__FILE__,__LINE__,"Didn't iterate over all of the families!");
    }
}

void PedigreeParseTester::checkAllPeopleThere() {

    int i_1 = 1;
    int i_2 = 2;
    int i_3 = 3;
    int i_4 = 4;
    int i_5 = 5;
    int i_6 = 6;
    int i_7 = 7;
    int i_8 = 8;
    int i_9 = 9;
    int i_10 = 10;
    int i_11 = 11;
    int i_12 = 12;
    int i_13 = 13;
    int i_14 = 14;
    int i_15 = 15;
    int i_16 = 16;
    int i_17 = 17;
    int i_18 = 18;
    int i_19 = 19;
    int i_20 = 20;
    int i_21 = 21;
    int i_22 = 22;
    int i_32 = 32;
    int i_33 = 33;
    int i_34 = 34;
    int i_35 = 35;
    int i_36 = 36;
    int i_37 = 37;
    int i_38 = 38;
    int i_39 = 39;
    int i_40 = 40;
    int i_41 = 41;
    int i_42 = 42;
    int i_43 = 43;
    int i_44 = 44;
    int i_45 = 45;
    int i_46 = 46;
    int i_47 = 47;
    int i_48 = 48;
    int i_49 = 49;
    int i_50 = 50;
    int i_51 = 51;
    int i_52 = 52;
    int i_53 = 53;
    int i_54 = 54;
    int i_55 = 55;
    int i_56 = 56;
    int i_57 = 57;
    int i_58 = 58;
    int i_602 = 602;
    int i__1 = -1;
    int i__4 = -4;
    int i__10 = -10;
    int i__13 = -13;
    int i__16 = -16;
    int i__19 = -19;
    int i__23 = -23;
    int i__27 = -27;
    int i__31 = -31;
    int i__34 = -34;
    int i__37 = -37;
    int i__40 = -40;
    int i__7 = -7;
    int i__43 = -43;
    int i__46 = -46;
    int i__49 = -49;
    int i__53 = -53;
    int i__74 = -74;

    unordered_set<int> expected({i_1,i_2,i_3,i_4,i_5,i_6,i_7,i_8,i_9,i_10,i_11,i_12,i_13,i_14,i_15,i_16,i_17,i_18,i_19,i_20,i_21,i_22,i_32,i_33,i_34,i_35,i_36,i_37,i_38,i_39,i_40,i_41,i_42,i_43,i_44,i_45,i_46,i_47,i_48,i_49,i_50,i_51,i_52,i_53,i_54,i_55,i_56,i_57,i_58,i_602,i__1,i__4,i__10,i__13,i__16,i__19,i__23,i__27,i__31,i__34,i__37,i__40,i__7,i__43,i__46,i__49,i__53,i__74});

    unordered_set<Node*> allPeople = _dah->getAllNodes();
    _checkResult(allPeople,expected);
}

void PedigreeParseTester::checkFamilyCreation() {

    
    // 1,2:[32,13,12,11,10,9,8,7,6,5,4,3]
    Person* parent_1 = _getPerson(1);
    Person* parent_2 = _getPerson(2);
    Person* child_32 = _getPerson(32);
    Person* child_3 = _getPerson(3);

    unordered_set<Node*> children = _dah->getChildren(parent_1);
    unordered_set<int> expected = unordered_set<int>({32,13,12,11,10,9,8,7,6,5,4,3});
    _checkResult(children,expected);
    
    children = _dah->getChildren(parent_2);
    expected = unordered_set<int>({32,13,12,11,10,9,8,7,6,5,4,3});
    _checkResult(children,expected);
    
    unordered_set<Node*> parents = _dah->getParents(child_32);
    expected = unordered_set<int>({1,2});
    _checkResult(parents,expected);
    
    parents = _dah->getParents(child_3);
    expected = unordered_set<int>({1,2});
    _checkResult(parents,expected);
    
    parents = _dah->getParents(parent_1);
    expected = unordered_set<int>({});
    _checkResult(parents,expected);
    
    // 13,14:[41,42,43,44,45]
    Person* parent_13 = _getPerson(13);
    children = _dah->getChildren(parent_13);
    expected = unordered_set<int>({41,42,43,44,45});
    _checkResult(children,expected);
    
    Person* child_602 = _getPerson(602);
    children = _dah->getChildren(child_602);
    expected = unordered_set<int>({});
    _checkResult(children,expected);
}

void PedigreeParseTester::checkFamilyCreationNot1084LN() {

    unordered_set<int> expected;
    unordered_set<Node*> children;
    unordered_set<Node*> parents;

    Person* child_7 = _getPerson(7);
    parents = _dah->getParents(child_7);
    expected = unordered_set<int>({4,6});
    _checkResult(parents,expected);

    Person* parent_4 = _getPerson(4);
    children = _dah->getChildren(parent_4);
    expected = unordered_set<int>({5,7});
    _checkResult(children,expected);
}

void PedigreeParseTester::checkFamilyFunctionsNot1084LN() {
    unordered_set<int> expected;
    unordered_set<Node*> nodes;
    unordered_set<Family*> families;
    
    Person* p_4 = _getPerson(4);
    families = _dah->getFamilies(p_4);
    if(families.size() != 2) {
        failWithMessage(__FILE__,__LINE__,"Wrong number of families");
    }

    Person* p_21 = _getPerson(21);
    families = _dah->getFamilies(p_21);
    if(families.size() != 1) {
        failWithMessage(__FILE__,__LINE__,"Wrong number of families");
    }
    Family* fam = *(families.begin());
    nodes = _dah->getNodesInFamily(fam);
    expected = unordered_set<int>({5,21,22,23});
    _checkResult(nodes,expected);

    nodes = _dah->getParents(fam);
    expected = unordered_set<int>({5,21});
    _checkResult(nodes,expected);

    nodes = _dah->getChildren(fam);
    expected = unordered_set<int>({22,23});
    _checkResult(nodes,expected);
}

void PedigreeParseTester::checkIteratorFunctionsNot1084LN() {

    unordered_set<Node*> nodes;
    unordered_set<Family*> families;
    NodeIterator result;
    unordered_set<int> expected;

    Person* p_7 = _getPerson(7);
    result = _dah->getNodesUpFrom(p_7);
    expected = unordered_set<int>({1,2,3,4,5,6,8,9,10,21,22,23,24,25,26,27,28});
    _checkResult(result,expected);

    Person* p_3 = _getPerson(3);
    Person* p_25 = _getPerson(25);
    families = _dah->getFamilies(p_25);
    if(families.size() != 1) {
        failWithMessage(__FILE__,__LINE__,"Wrong number of families");
    }
    Family* fam = *(families.begin());

    result = _dah->getAllFromFamilyExceptFromNode(fam,p_3);
    expected = unordered_set<int>({24,25});
    _checkResult(result,expected);
    
    result = _dah->getNodesUpFromExceptFromFamily(p_3,fam);
    expected = unordered_set<int>({1,2});
    _checkResult(result,expected);

    result = _dah->getNodesDownFromExceptFromFamily(p_3,fam);
    expected = unordered_set<int>({4,5,6,7,8,9,10,21,22,23,26,27,28});
    _checkResult(result,expected);
}

void pedigreeParseTest1084LN() {
    PedigreeParseTester tester("/Users/Eddie/kec-bot/app/pedigreeDataOLDBUTWORKS/1084LN.json");
    tester.checkAllPeopleThere();
    tester.checkFamilyCreation();
}

void pedigreeParseTest_test_pedigreeParse() {
    PedigreeParseTester tester("/Users/Eddie/kec-bot/app/pedigreeDataOLDBUTWORKS/test_pedigreeParse.json");
    tester.checkFamilyCreationNot1084LN();
    tester.checkFamilyFunctionsNot1084LN();
    tester.checkIteratorFunctionsNot1084LN();
}

void allPedigreeParseTests() {
    pedigreeParseTest1084LN();
    pedigreeParseTest_test_pedigreeParse();
}
