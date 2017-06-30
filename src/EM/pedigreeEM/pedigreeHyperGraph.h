#ifndef NODEEMDELEGATE_H
#define NODEEMDELEGATE_H


#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/nodeIterator.h"
#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraph.h"
#include "/Users/Eddie/hyperGraphEM/src/logVar/logVar.h"
#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/forwardsBackwards.h"
#include <unordered_map>
#include <vector>


using namespace std;

enum Allele {AA,Aa,aA,aa,NUMB_ALLELES};
enum Shading {shaded,unshaded,NUMB_SHADING};
enum Sex {female,male,unknown,NUMB_SEXES};

class Person;
class NuclearFamily;
class Pedigree;

class PedigreeSoftEMOptimizer;

class NumberOfHiddenStatesGetter;
class EmissionFunction;
class TransitionFunction;
class RootProbFunction;
class FowrardsBackwards;


class NumberOfAllelesGetter: public NumberOfHiddenStatesGetter {
public:
    unsigned operator()(Node* node) {
        failWithMessage(__FILE__,__LINE__,"assert");
        return NUMB_ALLELES;
    }
};

class ShadingFunction: public EmissionFunction {
public:
    LogVar operator()(Node* node, unsigned x) {
        failWithMessage(__FILE__,__LINE__,"assert");
        return LogVar();
    }
};

class ParentChildTransitionFunction: public TransitionFunction {

public:
    LogVar operator()(Family* family, Node* child, const unordered_map<Node*,unsigned>& X, unsigned x) {
        failWithMessage(__FILE__,__LINE__,"assert");
        return LogVar();
    }
};

class RootAncestorProbFunction: public RootProbFunction {

    Pedigree* _pedigree;
public:
    RootAncestorProbFunction(Pedigree* pedigree): _pedigree(pedigree) {}

    LogVar operator()(Node* node, unsigned x);
};

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

class NuclearFamily : public Family {

public:

    NuclearFamily(int id, unordered_set<Person*> parents, unordered_set<Person*> children): Family(id,unordered_set<Node*>(parents.begin(),parents.end()),unordered_set<Node*>(children.begin(),children.end())) {}

    /* TESTS */
    static void NuclearFamilyTests();

};


class Pedigree : public DirectedAcyclicHypergraph {

    unordered_map<Person*,vector<LogVar>> _rootProbs;

    NumberOfAllelesGetter _numbAlleleGetter;
    ShadingFunction _emissionFunc;
    ParentChildTransitionFunction _transitionFunc;
    RootAncestorProbFunction _rootProbFunc;

    FowrardsBackwards _forwardsBackwardsCalculator;

public:

    Pedigree(const unordered_set<NuclearFamily*>& families) : 
        DirectedAcyclicHypergraph(unordered_set<Family*>(families.begin(),families.end())),
        _numbAlleleGetter(),
        _emissionFunc(),
        _transitionFunc(),
        _rootProbFunc(this),
        _forwardsBackwardsCalculator(this,&_numbAlleleGetter,&_emissionFunc,&_transitionFunc,&_rootProbFunc) {}

    LogVar getAValue(Person* node, int x);
    LogVar getBValue(NuclearFamily* family, const unordered_map<Person*,unsigned int>& X);
    LogVar getCValue(NuclearFamily* family, Person* child, const unordered_map<Person*,unsigned int>& X, int x);

    void calcABCVals();

    void updateRootProb(Person* root, int x, LogVar val);
    LogVar getRootProb(Person* root, int x);

    /* TESTS */
    static void PedigreeTests();
    static void getAValueTests();
    static void getBValueTests();
    static void getCValueTests();
    static void updateRootProbsTests();
    static void getRootProbTests();

};



#endif

