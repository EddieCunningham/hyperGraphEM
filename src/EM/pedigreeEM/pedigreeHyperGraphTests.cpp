#include <iostream>
#include <unordered_set>
#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraph.h"
#include "/Users/Eddie/hyperGraphEM/src/tests/testMain.h"
#include "/Users/Eddie/hyperGraphEM/src/pedigreeParse/pedigreeToPedigree.h"
#include "/Users/Eddie/hyperGraphEM/src/messages/errorMessages.h"
#include "/Users/Eddie/hyperGraphEM/src/helper/nestedLoop.h"
#include "/Users/Eddie/hyperGraphEM/src/EM/pedigreeEM/pedigreeHyperGraph.h"
#include "/Users/Eddie/hyperGraphEM/src/pedigreeParse/pedigreeToPedigree.h"
#include "/Users/Eddie/hyperGraphEM/src/tests/testMain.h"



void makeSureIsOne(const LogVar& val) {
    if(val != 1.0) {
        failWithMessage(__FILE__,__LINE__,"val wasn't 1!");
    }
}


void Person::getShadingTests() {

    cout << "not implemented" << endl;
    failWithMessage(__FILE__,__LINE__,"assert statement");
}

void Person::getSexTests() {

    PedigreeToPedigree pedigreeStruct("/Users/Eddie/kec-bot/app/pedigreeDataOLDBUTWORKS/1084LN.json");

    Person* p13 = pedigreeStruct.getPerson(13);
    if(p13->getSex() != male) {
        failWithMessage(__FILE__,__LINE__,"should have been male");
    }

    Person* p14 = pedigreeStruct.getPerson(14);
    if(p14->getSex() != female) {
        failWithMessage(__FILE__,__LINE__,"should have been female");
    }

    Person* p__19 = pedigreeStruct.getPerson(-19);
    if(p__19->getSex() != male) {
        failWithMessage(__FILE__,__LINE__,"should have been male");
    }

    Person* p__23 = pedigreeStruct.getPerson(-23);
    if(p__23->getSex() != female) {
        failWithMessage(__FILE__,__LINE__,"should have been female");
    }
}

void Person::getHiddenStatesNTests() {
    cout << "not implemented" << endl;
    failWithMessage(__FILE__,__LINE__,"assert statement");
}

void Person::getObservedStatesNTests() {
    cout << "not implemented" << endl;
    failWithMessage(__FILE__,__LINE__,"assert statement");
}


void Person::PersonTests() {

    Person test = Person(-5,nullptr);

    // Person::getShadingTests();
    Person::getSexTests() ;
    // Person::getHiddenStatesNTests();
    // Person::getObservedStatesNTests();
}




void NuclearFamily::NuclearFamilyTests() {
    
    
}


void Pedigree::getAValueTests() {

    PedigreeToPedigree pedigreeStruct("/Users/Eddie/kec-bot/app/pedigreeDataOLDBUTWORKS/1084LN.json");
    Pedigree* pedigree = pedigreeStruct.getPedigree();

    Person* p__23 = pedigreeStruct.getPerson(-23);

    LogVar aVal = pedigree->getAValue(p__23, 0);
    aVal = pedigree->getAValue(p__23, 1);
    aVal = pedigree->getAValue(p__23, 2);
    aVal = pedigree->getAValue(p__23, 3);
    aVal = pedigree->getAValue(p__23, 4);
    aVal = pedigree->getAValue(p__23, 5);

    PedigreeToPedigree pedigreeStruct2("/Users/Eddie/kec-bot/app/pedigreeDataOLDBUTWORKS/test_cycle.json");
    pedigree = pedigreeStruct2.getPedigree();
    Person *p_6 = pedigreeStruct2.getPerson(6);
    aVal = pedigree->getAValue(p_6,0);
    aVal = pedigree->getAValue(p_6,1);
    aVal = pedigree->getAValue(p_6,2);
    aVal = pedigree->getAValue(p_6,3);

    Person *p_9 = pedigreeStruct2.getPerson(9);
    aVal = pedigree->getAValue(p_9,0);
    aVal = pedigree->getAValue(p_9,1);
    aVal = pedigree->getAValue(p_9,2);
    aVal = pedigree->getAValue(p_9,3);

    Person *p_3 = pedigreeStruct2.getPerson(3);
    aVal = pedigree->getAValue(p_3,0);
    aVal = pedigree->getAValue(p_3,1);
    aVal = pedigree->getAValue(p_3,2);
    aVal = pedigree->getAValue(p_3,3);
}

void Pedigree::getBValueTests() {


    PedigreeToPedigree pedigreeStruct("/Users/Eddie/kec-bot/app/pedigreeDataOLDBUTWORKS/1084LN.json");
    Pedigree* pedigree = pedigreeStruct.getPedigree();

    Person* p_7 = pedigreeStruct.getPerson(7);
    unordered_set<NuclearFamily*> upFams = p_7->getUpFamilies();
    NuclearFamily* fam = (NuclearFamily*)(*(upFams.begin()));

    unordered_set<Person*> parents = fam->getParents();
    unordered_map<Person*,unsigned> X;
    for(Node* node: parents) {
        X.insert({(Person*)node,0});
    }

    LogVar val = pedigree->getBValue(fam,X);

    PedigreeToPedigree pedigree2("/Users/Eddie/kec-bot/app/pedigreeDataOLDBUTWORKS/test_cycle.json");    
    pedigree = pedigree2.getPedigree();

    Person* p9 = pedigreeStruct.getPerson(9);
    fam = (NuclearFamily*)(*(p9->getUpFamilies().begin()));

    unordered_set<Person*> parents2 = fam->getParents();
    unordered_map<Person*,unsigned> X2;
    for(Node* node: parents2) {
        X2.insert({(Person*)node,0});
    }

    val = pedigree->getBValue(fam,X2);

}
void Pedigree::getCValueTests() {
    PedigreeToPedigree pedigreeStruct("/Users/Eddie/kec-bot/app/pedigreeDataOLDBUTWORKS/1084LN.json");
    Pedigree* pedigree = pedigreeStruct.getPedigree();

    Person* p_7 = pedigreeStruct.getPerson(7);
    NuclearFamily* fam = (NuclearFamily*)(*(p_7->getUpFamilies().begin()));

    unordered_set<Person*> parents = fam->getParents();
    unordered_map<Person*,unsigned> X;
    for(Node* node: parents) {
        X.insert({(Person*)node,0});
    }

    LogVar val = pedigree->getCValue(fam,p_7,X,0);

    PedigreeToPedigree pedigree2("/Users/Eddie/kec-bot/app/pedigreeDataOLDBUTWORKS/test_cycle.json");    
    pedigree = pedigree2.getPedigree();

    Person* p9 = pedigreeStruct.getPerson(9);
    fam = (NuclearFamily*)(*(p9->getUpFamilies().begin()));

    unordered_set<Person*> parents2 = fam->getParents();
    unordered_map<Person*,unsigned> X2;
    for(Node* node: parents2) {
        X2.insert({(Person*)node,0});
    }

    val = pedigree->getCValue(fam,p9,X2,0);

    Person* p3 = pedigreeStruct.getPerson(3);
    fam = (NuclearFamily*)(*(p3->getUpFamilies().begin()));

    unordered_set<Person*> parents3 = fam->getParents();
    unordered_map<Person*,unsigned> X3;
    for(Node* node: parents3) {
        X3.insert({(Person*)node,0});
    }

    val = pedigree->getCValue(fam,p3,X3,0);
}

void Pedigree::updateRootProbsTests() {
    // trivial (hopefully)
}
void Pedigree::getRootProbTests() {
    // trivial (hopefully)
}

// sum over n_x = i in A = 1
void test1(Pedigree* pedigree) {
    
    unordered_set<Person*> nodes = pedigree->getAllNodes();
    for(Node* node: nodes) {
        Person* person = (Person*)node;
        int n = person->getHiddenStatesN();
        LogVar sum;
        for(int i=0; i<n; ++i) {
            sum += pedigree->getAValue(person,i);
        }
        makeSureIsOne(sum);
    }
}

// sum over ^(e)_x = X in B = 1
void test2(Pedigree* pedigree) {


    vector<unsigned> indices;
    vector<unsigned> maxVals;
    unordered_set<NuclearFamily*> families = pedigree->getAllFamilies();

    for(NuclearFamily* family: families) {

        NuclearFamily* fam = (NuclearFamily*)family;
        unordered_set<Person*> parents = fam->getParents();

        unordered_map<Person*,unsigned> X;
        unordered_map<Person*,unsigned> XMaxVals;

        for(Node* parent: parents) {
            Person* person = (Person*)parent;
            int n = person->getHiddenStatesN();
            X[person] = 0;
            XMaxVals[person] = n;
        }

        LogVar sum;
        MapIterator<Person*> it(X,XMaxVals);
        do {
            LogVar bVal = pedigree->getBValue(fam,it.getMap());
            sum += bVal;
        } while(it.increment());
        makeSureIsOne(sum);
    }
}

// sum over ^(e)_x = X, n_x = i in C = 1
void test3(Pedigree* pedigree) {


    vector<unsigned> indices;
    vector<unsigned> maxVals;
    unordered_set<NuclearFamily*> families = pedigree->getAllFamilies();

    for(Family* family: families) {

        NuclearFamily* fam = (NuclearFamily*)family;
        unordered_set<Person*> parents = fam->getParents();
        unordered_set<Person*> children = fam->getChildren();

        for(Node* node: children) {

            unordered_map<Person*,unsigned> X;
            unordered_map<Person*,unsigned> XMaxVals;

            for(Node* parent: parents) {
                Person* person = (Person*)parent;
                int n = person->getHiddenStatesN();
                X[person] = 0;
                XMaxVals[person] = n;
            }

            Person* child = (Person*)node;
            int n = child->getHiddenStatesN();
            
            LogVar sum;
            for(int x=0; x<n; ++x) {
                MapIterator<Person*> it(X,XMaxVals);
                do {
                    LogVar cVal = pedigree->getCValue(fam,child,it.getMap(),x);
                    sum += cVal;
                } while(it.increment());
            }
            makeSureIsOne(sum);
        }
    }
}

// sum over i in root probs = 1
void test4(Pedigree* pedigree) {

    unordered_set<Person*> nodes = pedigree->getAllNodes();
    for(Node* node: nodes) {

        Person* person = (Person*)node;
        int n = person->getHiddenStatesN();

        LogVar sum;
        for(int i=0; i<n; ++i) {
            LogVar rootProb = pedigree->getRootProb(person,i);
            sum += rootProb;
        }
        makeSureIsOne(sum);
    }
}

void PedigreeEMTests(string filename) {
    PedigreeToPedigree pedigreeStruct(filename);
    Pedigree* pedigree = pedigreeStruct.getPedigree();

    test1(pedigree);
    test2(pedigree);
    test3(pedigree);
    test4(pedigree);


    // NEED TO ADD MORE TESTS TO SHOW THAT 
    // THE DIFFERENT VALUES, WHEN MARGINALIZED OVER
    // EQUAL EACH OTHER!
}


void allPedigreeEMTests() {

    string filename1 = "/Users/Eddie/kec-bot/app/pedigreeDataOLDBUTWORKS/1084LN.json";
    string filename2 = "/Users/Eddie/kec-bot/app/pedigreeDataOLDBUTWORKS/test_pedigreeParse.json";

    PedigreeEMTests(filename2);
}



void Pedigree::PedigreeTests() {
    Pedigree pedigree = Pedigree(unordered_set<NuclearFamily*>({nullptr}));

    Pedigree::getAValueTests();
    Pedigree::getBValueTests();
    Pedigree::getCValueTests();
    Pedigree::updateRootProbsTests();
    Pedigree::getRootProbTests();

    // allPedigreeEMTests();

}



void allPedigreeHyperGraphTests() {
    Person::PersonTests();
    NuclearFamily::NuclearFamilyTests();
    Pedigree::PedigreeTests();
}


