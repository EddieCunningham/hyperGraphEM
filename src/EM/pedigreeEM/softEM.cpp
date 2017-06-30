#include "/Users/Eddie/hyperGraphEM/src/EM/pedigreeEM/softEM.h"



void PedigreeSoftEMOptimizer::_calculateABCValues() {
    for(Pedigree* pedigree: _trainingSet) {
        pedigree->calcABCVals();
    }
}

void PedigreeSoftEMOptimizer::_updateTransitionProbs() {
}

void PedigreeSoftEMOptimizer::_updateEmissionProbs() {
}

double PedigreeSoftEMOptimizer::getTransitionProb(Person* parentA, int a_x, Person* parentB, int b_x, Person* child, int x) {

    Sex sexIndex = child->getSex();
    Person* mother;
    Person* father;
    sortMates(parentA,parentB,mother,father);
    
    return -1;

}

double PedigreeSoftEMOptimizer::getEmissionProb(Person* person, int i) {
    return -1;
}

double PedigreeSoftEMOptimizer::getRootProb(Person* root, int i) {
    return -1;
}

void PedigreeSoftEMOptimizer::EStep() {

}

void PedigreeSoftEMOptimizer::MStep() {

}



