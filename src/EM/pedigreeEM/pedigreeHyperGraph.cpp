#include "/Users/Eddie/hyperGraphEM/src/EM/pedigreeEM/pedigreeHyperGraph.h"


Person::Person(int id, Data* data): Node(id,data) {}

int Person::getHiddenStatesN() {
    return -1;
}

int Person::getObservedStatesN() {
    return -1;
}

/* ---------------------------------------------------- */

LogVar Person::_computeUValRootCase(int x) {

    LogVar lvEmissionProb;
    LogVar lvRootProb;
    
    double emissionProb = _opt->getEmissionProb(this,x);
    double rootProb = _dah->getRootProb(this,x);

    lvEmissionProb = emissionProb;
    lvRootProb = rootProb;

    LogVar ans;
    ans = lvEmissionProb * lvRootProb;

    return ans;
}

LogVar _computeUValNonRootCase(FamilyWrapper* upFamily, int x) {


}

LogVar Person::_computeUVal(int x) {
    LogVar ans;

    vector<Family*> upFamilies = _getUpFamilies();
    if(upFamilies.size() == 0) {
        return _computeUValRootCase(x);
    }
    else if(upFamilies.size() == 1) {
        FamilyWrapper* upFamily = (FamilyWrapper*)(upFamilies.at(0));
        return _computeUValNonRootCase(upFamily, x);
    }
    else {
        failWithMessage(__FILE__,__LINE__,"Should only have at most one up family!");
    }

}

LogVar Person::_cycleUBaseCase(int x) {
    LogVar ans;
    if(x == _currentlyBeingUpdated) {
        ans = 1.0;
    }
    else {
        ans = 0.0;
    }
    return ans;
}

LogVar Person::_getUVal(int x, int lastUpdateVal) {

    // algorithm:
    // - compute uVal using dynamic programming
    // - keep track of what index is currently being updated
    // - if lastUpdatedVal is different from _updateVal, 
    //   then throw away currently stored value and recompute
    
    if(_updateVal != lastUpdateVal) {
        _computeUVal(x);
    }
    else {
        // then we have encountered a cycle and have to do a special base case
        _cycleUBaseCase(x);
    }


}

/* ---------------------------------------------------- */

LogVar Person::_computeAlphaVal(FamilyWrapper* family, const unordered_map<Person*,unsigned int>& X) {
    return LogVar();

}

LogVar Person::_getAlphaVal(FamilyWrapper* family, const unordered_map<Person*,unsigned int>& X) {
    return LogVar();

}

/* ---------------------------------------------------- */

LogVar Person::_computeBetaValue(FamilyWrapper* family, int x) {
    return LogVar();

}

LogVar Person::_getBetaValue(FamilyWrapper* family, int x) {
    return LogVar();

}

/* ---------------------------------------------------- */

LogVar Person::_computeGammaValue(FamilyWrapper* family, const unordered_map<Person*,unsigned int>& X, int x) {
    return LogVar();

}

LogVar Person::_getGammaValue(FamilyWrapper* family, const unordered_map<Person*,unsigned int>& X, int x) {
    return LogVar();

}

/* ---------------------------------------------------- */

Sex Person::getSex() {
    return female;
}

LogVar Person::getUVal(int x) {
    return LogVar();

}

LogVar Person::getAlphaVal(FamilyWrapper* family, const unordered_map<Person*,unsigned int>& X) {
    return LogVar();

}

LogVar Person::getBetaValue(FamilyWrapper* family, int x) {
    return LogVar();

}

LogVar Person::getGammaValue(FamilyWrapper* family, const unordered_map<Person*,unsigned int>& X, int x) {
    return LogVar();

}

LogVar Person::getAValue(int x) {
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

LogVar FamilyWrapper::getBValue(const unordered_map<Person*,unsigned int>& X) {
    return LogVar();

}
LogVar FamilyWrapper::getCValue(Person* child, const unordered_map<Person*,unsigned int>& X, int x) {
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

LogVar DAH::getBValue(FamilyWrapper* family, const unordered_map<Person*,unsigned int>& X) {
    return LogVar();

}

LogVar DAH::getCValue(FamilyWrapper* family, Person* child, const unordered_map<Person*,unsigned int>& X, int x) {
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

double DAH::getRootProb(Person* root, int x) {
    return -1;
}
