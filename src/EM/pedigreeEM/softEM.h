#ifndef SOFTEM_H
#define SOFTEM_H

#include <vector>
#include <unordered_map>
#include "/Users/Eddie/hyperGraphEM/src/EM/pedigreeEM/hyperGraphDelegate.h"

using namespace std;


void sortMates(PersonWrapper* mateA, PersonWrapper* mateB, PersonWrapper* mother, PersonWrapper* father);

class PedigreeSoftEMOptimizer {

    vector<DAHWrapper*> _trainingSet;

    unordered_map<Sex,vector<vector<double>>> _emissionProbs;
    unordered_map<Sex,vector<vector<vector<double>>>> _transitionProbs;

    /* --------- E Step --------- */
    void _calculateAValues();
    void _calculateBValues();
    void _calculateCValues();

    /* --------- M Step --------- */
    void _updateRootProbs();
    void _updateTransitionProbs();
    void _updateEmissionProbs();

public:

    PedigreeSoftEMOptimizer(vector<DAHWrapper*> trainingSet): _trainingSet(trainingSet){}

    double getTransitionProb(PersonWrapper* parentA, PersonWrapper* parentB, PersonWrapper* child, int i, int j, int k);
    double getEmissionProb(PersonWrapper* person, int i);
    double getRootProb(PersonWrapper* root, int i);

    void EStep();
    void MStep();
};

class PedigreeEMModel {

    PedigreeSoftEMOptimizer trainer;

public:
    PedigreeEMModel();

    void train(const vector<DAHWrapper*>& trainingSet);
    void predict(const DAHWrapper* test);
};









#endif