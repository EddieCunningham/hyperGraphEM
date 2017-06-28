#include <iostream>
#include <unordered_set>
#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraph.h"
#include "/Users/Eddie/hyperGraphEM/src/tests/testMain.h"
#include "/Users/Eddie/hyperGraphEM/src/pedigreeParse/pedigreeToDAH.h"
#include "/Users/Eddie/hyperGraphEM/src/messages/errorMessages.h"
#include "/Users/Eddie/hyperGraphEM/src/helper/nestedLoop.h"

void makeSureIsOne(const LogVar& val) {
    if(val != 1.0) {
        failWithMessage(__FILE__,__LINE__,"val wasn't 1!");
    }
}

// sum over n_x = i in A = 1
void test1(DAH* dah) {
    
    unordered_set<Node*> nodes = dah->getAllNodes();
    for(Node* node: nodes) {
        Person* person = (Person*)node;
        int n = person->getHiddenStatesN();
        LogVar sum;
        for(int i=0; i<n; ++i) {
            sum += person->getAValue(i);
        }
        makeSureIsOne(sum);
    }
}

// sum over ^(e)_x = X in B = 1
void test2(DAH* dah) {


    vector<unsigned> indices;
    vector<unsigned> maxVals;
    unordered_set<Family*> families = dah->getAllFamilies();

    for(Family* family: families) {

        FamilyWrapper* fam = (FamilyWrapper*)family;
        unordered_set<Node*> parents = fam->getParents();

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
            LogVar bVal = fam->getBValue(it.getMap());
            sum += bVal;
        } while(it.increment());
        makeSureIsOne(sum);
    }
}

// sum over ^(e)_x = X, n_x = i in C = 1
void test3(DAH* dah) {


    vector<unsigned> indices;
    vector<unsigned> maxVals;
    unordered_set<Family*> families = dah->getAllFamilies();

    for(Family* family: families) {

        FamilyWrapper* fam = (FamilyWrapper*)family;
        unordered_set<Node*> parents = fam->getParents();
        unordered_set<Node*> children = fam->getChildren();

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
                    LogVar cVal = fam->getCValue(child,it.getMap(),x);
                    sum += cVal;
                } while(it.increment());
            }
            makeSureIsOne(sum);
        }
    }
}

// sum over i in root probs = 1
void test4(DAH* dah) {

    unordered_set<Node*> nodes = dah->getAllNodes();
    for(Node* node: nodes) {

        Person* person = (Person*)node;
        int n = person->getHiddenStatesN();

        LogVar sum;
        for(int i=0; i<n; ++i) {
            double rootProb = dah->getRootProb(person,i);
            sum += rootProb;
        }
        makeSureIsOne(sum);
    }
}

void DAHEMTests(string filename) {
    pedigreeToDAH pedigree(filename);
    DAH* dah = pedigree.getDAH();

    test1(dah);
    test2(dah);
    test3(dah);
    test4(dah);
}


void allDAHEMTests() {

    string filename1 = "/Users/Eddie/kec-bot/app/pedigreeDataOLDBUTWORKS/1084LN.json";
    string filename2 = "/Users/Eddie/kec-bot/app/pedigreeDataOLDBUTWORKS/test_pedigreeParse.json";

    DAHEMTests(filename2);
}
