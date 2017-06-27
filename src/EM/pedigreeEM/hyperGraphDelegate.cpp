#include "/Users/Eddie/hyperGraphEM/src/EM/pedigreeEM/hyperGraphDelegate.h"


Person::Person(int id, Data* data): Node(id,data) {}

LogVar Person::_computeUVal(int x) {
    return LogVar();

}

LogVar Person::_computeAlphaVal(FamilyWrapper* family, const unordered_map<Person*,int>& X) {
    return LogVar();

}

LogVar Person::_computeBetaValue(FamilyWrapper* family, int x) {
    return LogVar();

}

LogVar Person::_computeGammaValue(FamilyWrapper* family, const unordered_map<Person*,int>& X, int x) {
    return LogVar();

}

LogVar Person::_getUVal(int x) {
    return LogVar();

}

LogVar Person::_getAlphaVal(FamilyWrapper* family, const unordered_map<Person*,int>& X) {
    return LogVar();

}

LogVar Person::_getBetaValue(FamilyWrapper* family, int x) {
    return LogVar();

}

LogVar Person::_getGammaValue(FamilyWrapper* family, const unordered_map<Person*,int>& X, int x) {
    return LogVar();

}

Sex Person::getSex() {
    return female;
}

LogVar Person::getUVal(int x) {
    return LogVar();

}

LogVar Person::getAlphaVal(FamilyWrapper* family, const unordered_map<Person*,int>& X) {
    return LogVar();

}

LogVar Person::getBetaValue(FamilyWrapper* family, int x) {
    return LogVar();

}

LogVar Person::getGammaValue(FamilyWrapper* family, const unordered_map<Person*,int>& X, int x) {
    return LogVar();

}

LogVar Person::getAValue(Person* node, int x) {
    return LogVar();

}

/* -------------------------------- */

FamilyWrapper::FamilyWrapper(int id, vector<Person*> parents, vector<Person*> children): Family(id) {
    
    for(Person* parent: parents) {
        _addParent(parent);
    }
    
    for(Person* child: children) {
        _addChild(child);
    }
    
}

LogVar FamilyWrapper::getBValue(const vector<int>& X) {
    return LogVar();

}
LogVar FamilyWrapper::getCValue(Person* child, const vector<int>& X, int x) {
    return LogVar();

}

/* -------------------------------- */

DAH::DAH(const vector<FamilyWrapper*>& families) {
    for(FamilyWrapper* family: families) {
        _addFamily(family);
    }
}

LogVar DAH::getAValue(Person* node, int x) {
    return LogVar();

}

LogVar DAH::getBValue(FamilyWrapper* family, const vector<int>& X) {
    return LogVar();

}

LogVar DAH::getCValue(FamilyWrapper* family, Person* child, const vector<int>& X, int x) {
    return LogVar();

}

void DAH::calcAVals() {

}

void DAH::calcBVals() {

}

void DAH::calcCVals() {

}

void DAH::updateRootProbs() {

}

double DAH::getRootProb(Person* root) {
    return -1;
}
