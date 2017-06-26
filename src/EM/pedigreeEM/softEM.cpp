#include "/Users/Eddie/hyperGraphEM/src/EM/pedigreeEM/softEM.h"



void PedigreeSoftEMOptimizer::_calculateAValues() {
    for(DAHWrapper* dah: _trainingSet) {
        dah->calcAVals;
    }
}

void PedigreeSoftEMOptimizer::_calculateBValues() {
    for(DAHWrapper* dah: _trainingSet) {
        dah->calcBVals;
    }
}

void PedigreeSoftEMOptimizer::_calculateCValues() {
    for(DAHWrapper* dah: _trainingSet) {
        dah->calcCVals;
    }
}

void PedigreeSoftEMOptimizer::_updateRootProbs() {
    for(DAHWrapper* dah: _trainingSet) {
        dah->updateRootProbs;
    }
}

void PedigreeSoftEMOptimizer::_updateTransitionProbs() {
}

void PedigreeSoftEMOptimizer::_updateEmissionProbs() {
}

double PedigreeSoftEMOptimizer::getTransitionProb(PersonWrapper* parentA, int a_x, PersonWrapper* parentB, int b_x, PersonWrapper* child, int x) {

    Sex sexIndex = child->getSexIndex();
    PersonWrapper* mother;
    PersonWrapper* father;
    sortMates(parentA,parentB,mother,father);

}

double PedigreeSoftEMOptimizer::getEmissionProb(PersonWrapper* person, int i) {

}

double PedigreeSoftEMOptimizer::getRootProb(PersonWrapper* root, int i) {

}

void PedigreeSoftEMOptimizer::EStep() {

}

void PedigreeSoftEMOptimizer::MStep() {

}



