#ifndef SOFTEM_H
#define SOFTEM_H

#include <vector>
#include <unordered_map>
#include "/Users/Eddie/hyperGraphEM/src/EM/pedigreeEM/hyperGraphDelegate.h"

using namespace std;


void sortMates(Person* mateA, Person* mateB, Person* mother, Person* father);

class PedigreeSoftEMOptimizer {

    vector<DAH*> _trainingSet;

    unordered_map<int,vector<vector<double>>> _emissionProbs;
    unordered_map<int,vector<vector<vector<double>>>> _transitionProbs;

    /* --------- E Step --------- */
    void _calculateAValues();
    void _calculateBValues();
    void _calculateCValues();

    /* --------- M Step --------- */
    void _updateRootProbs();
    void _updateTransitionProbs();
    void _updateEmissionProbs();

public:

    PedigreeSoftEMOptimizer(vector<DAH*> trainingSet): _trainingSet(trainingSet){}

    double getTransitionProb(Person* parentA, int a_x, Person* parentB, int b_x, Person* child, int x);
    double getEmissionProb(Person* person, int i);
    double getRootProb(Person* root, int i);

    void EStep();
    void MStep();
};

class PedigreeEMModel {

    PedigreeSoftEMOptimizer trainer;

public:
    PedigreeEMModel();

    void train(const vector<DAH*>& trainingSet);
    void predict(const DAH* test);
};









#endif
