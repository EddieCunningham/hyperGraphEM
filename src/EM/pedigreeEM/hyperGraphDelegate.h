#ifndef NODEEMDELEGATE_H
#define NODEEMDELEGATE_H


#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/nodeIterator.h"
#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraph.h"
#include "/Users/Eddie/hyperGraphEM/src/logVar/logVar.h"

using namespace std;

enum Sex {female,male,unknown};

class PersonWrapper {

    Sex _sex;
    int _updateVal;
    DAHWrapper* _dah;
    Node* _node;
    vector<double> _logU;
    vector<double> _logAlpha;
    unordered_map<FamilyWrapper*,vector<double>> _logBeta;
    unordered_map<FamilyWrapper*,vector<double>> _logGamma;


    LogVar _computeUVal(int x);
    LogVar _computeAlphaVal(FamilyWrapper* family, const unordered_map<PersonWrapper*,int>& X);
    LogVar _computeBetaValue(FamilyWrapper* family, int x);
    LogVar _computeGammaValue(FamilyWrapper* family, const unordered_map<PersonWrapper*,int>& X, int x);

    LogVar _getUVal(int x);
    LogVar _getAlphaVal(FamilyWrapper* family, const unordered_map<PersonWrapper*,int>& X);
    LogVar _getBetaValue(FamilyWrapper* family, int x);
    LogVar _getGammaValue(FamilyWrapper* family, const unordered_map<PersonWrapper*,int>& X, int x);
    
public:

    Sex getSex();

    /* -------- Dynamic Programming Functions -------- */
    LogVar getUVal(int x);
    LogVar getAlphaVal(FamilyWrapper* family, const unordered_map<PersonWrapper*,int>& X);
    LogVar getBetaValue(FamilyWrapper* family, int x);
    LogVar getGammaValue(FamilyWrapper* family, const unordered_map<PersonWrapper*,int>& X, int x);

    /* -------- P(n_x = i | Y) -------- */
    LogVar getAValue(PersonWrapper* node, int x);
};

class FamilyWrapper {
    Family* _family;

public:

    /* --------      P(^(f)_x = X | Y)      -------- */
    /* -------- P(^(f)_x = X , n_x = i | Y) -------- */
    LogVar getBValue(const vector<int>& X);
    LogVar getCValue(PersonWrapper* child, const vector<int>& X, int x);
};


class DAHWrapper {

    DirectedAcyclicHypergraph* _dah;
    unordered_map<Node*,PersonWrapper*> nodeToWrapper;
    unordered_map<Family*,FamilyWrapper*> familyToWrapper;

    unordered_map<PersonWrapper*,vector<double>> _rootProbs;

public:

    DAHWrapper(DirectedAcyclicHypergraph* dah);

    LogVar getAValue(PersonWrapper* node, int x);
    LogVar getBValue(FamilyWrapper* family, const vector<int>& X);
    LogVar getCValue(FamilyWrapper* family, PersonWrapper* child, const vector<int>& X, int x);

    void calcAVals();
    void calcBVals();
    void calcCVals();

    void updateRootProbs();
    double getRootProb(PersonWrapper* root);

};






#endif

