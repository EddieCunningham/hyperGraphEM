#ifndef NODEEMDELEGATE_H
#define NODEEMDELEGATE_H


#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/nodeIterator.h"
#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraph.h"
#include "/Users/Eddie/hyperGraphEM/src/logVar/logVar.h"
#include <unordered_map>
#include <vector>


using namespace std;

enum Sex {female,male,unknown};

class Person;
class FamilyWrapper;
class DAH;

class Person : public Node {

    DAH* _dah;
    PedigreeSoftEMOptimizer* _opt;

    Sex _sex;
    
    int _updateVal;
    int _currentlyBeingUpdated;

    vector<LogVar> _u;
    vector<LogVar> _alpha;
    unordered_map<FamilyWrapper*,vector<LogVar>> _beta;
    unordered_map<FamilyWrapper*,vector<LogVar>> _gamma;

    vector<LogVar> _A;
    unordered_map<FamilyWrapper*,vector<LogVar>> _C;


    LogVar _computeUValRootCase(int x);
    LogVar _computeUValNonRootCase(FamilyWrapper* upFamily, int x);
    LogVar _computeUVal(int x);

    LogVar _computeAlphaVal(FamilyWrapper* family, const unordered_map<Person*,unsigned int>& X);
    LogVar _computeBetaValue(FamilyWrapper* family, int x);
    LogVar _computeGammaValue(FamilyWrapper* family, const unordered_map<Person*,unsigned int>& X, int x);

    LogVar _getUVal(int x);
    LogVar _getAlphaVal(FamilyWrapper* family, const unordered_map<Person*,unsigned int>& X);
    LogVar _getBetaValue(FamilyWrapper* family, int x);
    LogVar _getGammaValue(FamilyWrapper* family, const unordered_map<Person*,unsigned int>& X, int x);
    
public:

    Person(int id, Data* data);

    Sex getSex();
    int getHiddenStatesN();
    int getObservedStatesN();

    /* -------- Dynamic Programming Functions -------- */
    LogVar getUVal(int x);
    LogVar getAlphaVal(FamilyWrapper* family, const unordered_map<Person*,unsigned int>& X);
    LogVar getBetaValue(FamilyWrapper* family, int x);
    LogVar getGammaValue(FamilyWrapper* family, const unordered_map<Person*,unsigned int>& X, int x);

    /* -------- P(n_x = i | Y) -------- */
    LogVar getAValue(int x);
};

class FamilyWrapper : public Family {

    vector<LogVar> _B;

public:

    FamilyWrapper(int id, vector<Person*> parents, vector<Person*> children);

    /* --------      P(^(f)_x = X | Y)      -------- */
    /* -------- P(^(f)_x = X , n_x = i | Y) -------- */
    LogVar getBValue(const unordered_map<Person*,unsigned int>& X);
    LogVar getCValue(Person* child, const unordered_map<Person*,unsigned int>& X, int x);
};


class DAH : public DirectedAcyclicHypergraph {

    unordered_map<Person*,vector<double>> _rootProbs;

public:

    DAH(const vector<FamilyWrapper*>& families);

    LogVar getAValue(Person* node, int x);
    LogVar getBValue(FamilyWrapper* family, const unordered_map<Person*,unsigned int>& X);
    LogVar getCValue(FamilyWrapper* family, Person* child, const unordered_map<Person*,unsigned int>& X, int x);

    void calcAVals();
    void calcBVals();
    void calcCVals();

    void updateRootProbs();
    double getRootProb(Person* root, int x);
};






#endif

