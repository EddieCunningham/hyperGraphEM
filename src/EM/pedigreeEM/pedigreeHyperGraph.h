#ifndef NODEEMDELEGATE_H
#define NODEEMDELEGATE_H


#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/nodeIterator.h"
#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraph.h"
#include "/Users/Eddie/hyperGraphEM/src/logVar/logVar.h"
#include <unordered_map>
#include <vector>


using namespace std;

enum Allele {AA,Aa,aA,aa,NUMB_ALLELES};
enum Shading {shaded,unshaded,NUMB_SHADING};
enum Sex {female,male,unknown,NUMB_SEXES};

class Person;
class FamilyWrapper;
class DAH;
class PedigreeSoftEMOptimizer;

class Person : public Node {

    Shading _shading = NUMB_SHADING;
    Sex _sex = NUMB_SEXES;

    void _initializeShading();

    void _initializeSexUsingMate();
    void _initializeSexFromData();
    void _initializeSex();

    void _initializeSexAndShading();

public:

    Person(int id, Data* data);

    Allele getAllele();
    Shading getShading();
    Sex getSex();
    int getHiddenStatesN();
    int getObservedStatesN();

    /* TESTS */
    static void PersonTests();
    static void getShadingTests();
    static void getSexTests();
    static void getHiddenStatesNTests();
    static void getObservedStatesNTests();
};

class FamilyWrapper : public Family {

public:

    FamilyWrapper(int id, unordered_set<Person*> parents, unordered_set<Person*> children): Family(id,unordered_set<Node*>(parents.begin(),parents.end()),unordered_set<Node*>(children.begin(),children.end())) {}

    /* TESTS */
    static void FamilyWrapperTests();

};


class DAH : public DirectedAcyclicHypergraph {

    unordered_map<Person*,vector<double>> _rootProbs;

public:

    DAH(const unordered_set<FamilyWrapper*>& families) : DirectedAcyclicHypergraph(unordered_set<Family*>(families.begin(),families.end())) {}

    LogVar getAValue(Person* node, int x);
    LogVar getBValue(FamilyWrapper* family, const unordered_map<Person*,unsigned int>& X);
    LogVar getCValue(FamilyWrapper* family, Person* child, const unordered_map<Person*,unsigned int>& X, int x);

    void calcAVals();
    void calcBVals();
    void calcCVals();

    void updateRootProbs();
    double getRootProb(Person* root, int x);

    /* TESTS */
    static void DAHTests();
    static void getAValueTests();
    static void getBValueTests();
    static void getCValueTests();
    static void calcAValsTests();
    static void calcBValsTests();
    static void calcCValsTests();
    static void updateRootProbsTests();
    static void getRootProbTests();

};






#endif

