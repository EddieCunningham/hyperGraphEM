#ifndef SOFTEM_H
#define SOFTEM_H

#include <vector>
#include <unordered_map>
#include "/Users/Eddie/hyperGraphEM/src/EM/pedigreeEM/pedigreeHyperGraph.h"


using namespace std;


class Person;
class NuclearFamily;
class Pedigree;


void sortMates(Person* mateA, Person* mateB, Person* mother, Person* father);

class PedigreeSoftEMOptimizer {

    vector<Pedigree*> _trainingSet;

    unordered_map<unsigned,vector<vector<LogVar>>> _emissionProbs;
    unordered_map<unsigned,vector<vector<vector<LogVar>>>> _transitionProbs;

    pair<unsigned,unsigned> _getMotherFatherIndices(const unordered_map<Person*,unsigned>& parents);

    /* --------- E Step --------- */
    void _calculateABCValues();

    /* --------- M Step --------- */
    void _updateRootProbs();

    void _updateTransitionProbs();
    
    void _updateEmissionProbs();

public:

    PedigreeSoftEMOptimizer(vector<Pedigree*> trainingSet): _trainingSet(trainingSet){}

    LogVar getTransitionProb(const unordered_map<Person*,unsigned>& parents, Person* child, unsigned x);
    LogVar getEmissionProb(Person* person, unsigned x);
    LogVar getRootProb(Pedigree* pedigree, Person* root, unsigned x);

    void EStep();
    void MStep();

    /* TESTS */
    static void PedigreeSoftEMOptimizerTests();
    static void getTransitionProbTests();
    static void getEmissionProbTests();
    static void getRootProbTests();
    static void EStepTests();
    static void MStepTests();
};

class PedigreeEMModel {

    PedigreeSoftEMOptimizer trainer;

public:
    PedigreeEMModel();

    void train(const vector<Pedigree*>& trainingSet);
    void predict(const Pedigree* test);

    /* TESTS */
    static void PedigreeEMModelTests();
    static void trainTests();
    static void predictTests();
};









#endif
