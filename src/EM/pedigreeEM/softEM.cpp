#include "/Users/Eddie/hyperGraphEM/src/EM/pedigreeEM/softEM.h"

pair<unsigned,unsigned> PedigreeSoftEMOptimizer::_getMotherFatherIndices(const unordered_map<Person*,unsigned>& parents) {
    if(parents.size() != 2) {
        failWithMessage(__FILE__,__LINE__,"Need only 2 parents!");
    }

    Person* mother = nullptr;
    unsigned mX;
    Person* father = nullptr;
    unsigned fX;
    for(pair<Person*,unsigned> thePair: parents) {

        Person* parent = thePair.first;
        if(parent->getSex() == female) {
            mother = parent;
            mX = thePair.second;
        }
        else if(parent->getSex() == male) {
            father = parent;
            mX = thePair.second;
        }
        else {
            failWithMessage(__FILE__,__LINE__,"Not taking into account unknown,unknown parents!");
        }
    }

    if(mother == nullptr || father == nullptr) {
        failWithMessage(__FILE__,__LINE__,"A parent wasn't initialized!");
    }
    return pair<unsigned,unsigned>(mX,fX);
}

void PedigreeSoftEMOptimizer::_calculateABCValues() {
    for(Pedigree* pedigree: _trainingSet) {
        pedigree->calcABCVals();
    }
}

void PedigreeSoftEMOptimizer::_updateRootProbs() {
    for(Pedigree* pedigree: _trainingSet) {
        for(pair<Person*,vector<LogVar>> rootAndProbs: pedigree->getRootProbs()) {
            Person* root = rootAndProbs.first;
            unsigned n = rootAndProbs.second.size();
            for(int i=0; i<n; ++i) {
                LogVar aVal = pedigree->getAValue(root,i);
                pedigree->updateRootProb(root,i,aVal);
            }
        }
    }
}

void PedigreeSoftEMOptimizer::_updateTransitionProbs() {


    for(unsigned sIndex=0; sIndex < NUMB_SEXES; ++sIndex) {

        int motherN = NUMB_ALLELES;
        int fatherN = NUMB_ALLELES;
        int childN = NUMB_ALLELES;
        vector<vector<LogVar>> sums(motherN,vector<LogVar>(fatherN,LogVar()));

        _transitionProbs.at(sIndex) = vector<vector<vector<LogVar>>>(motherN,
                                                vector<vector<LogVar>>(fatherN,
                                                        vector<LogVar>(childN,LogVar())));

        for(Pedigree* pedigree: _trainingSet) {

            unordered_set<NuclearFamily*> fams = pedigree->getAllFamilies();
            for(NuclearFamily* family: fams) {

                unordered_set<Person*> parentsAsNode = family->getParents();
                MapIterator<Person*> parentsMap = mapIteratorFromSet(parentsAsNode);
                do {

                    unordered_map<Person*,unsigned> parents = parentsMap.getMap();

                    pair<unsigned,unsigned> mXfX = _getMotherFatherIndices(parents);
                    unsigned mX = mXfX.first;
                    unsigned fX = mXfX.second;


                    unordered_set<Person*> children = family->getChildren();
                    for(Person* child: children) {

                        Sex sexIndex = child->getSex();
                        if(sIndex != sexIndex) {
                            continue;
                        }

                        LogVar sum;

                        unsigned n = child->getHiddenStatesN();
                        vector<LogVar> eachVal(n,LogVar());

                        for(int x=0; x<n; ++x) {

                            LogVar cVal;
                            cVal = pedigree->getCValue(family,child,parents,x);
                            sums.at(mX).at(fX) += cVal;
                            _transitionProbs.at(sexIndex).at(mX).at(fX).at(x) += cVal;
                        }

                    }
                } while(parentsMap.increment());
            }
        }

        for(int i=0; i<motherN; ++i) {
            for(int j=0; j<fatherN; ++j) {
                for(int k=0; k<childN; ++k) {
                    _transitionProbs.at(sIndex).at(i).at(j).at(k) /= sums.at(i).at(j);
                }
            }
        }
    }
}

void PedigreeSoftEMOptimizer::_updateEmissionProbs() {

    for(unsigned sIndex=0; sIndex<NUMB_SEXES; ++sIndex) {

        int numbAlleles = NUMB_ALLELES;
        int numbShades = NUMB_SHADING;
        _emissionProbs.at(sIndex) = vector<vector<LogVar>>(numbAlleles,vector<LogVar>(numbShades,LogVar()));

        vector<vector<LogVar>> sums(numbAlleles,vector<LogVar>(numbShades,LogVar()));

        for(Pedigree* pedigree: _trainingSet) {

            unordered_set<Person*> allPeople = pedigree->getAllNodes();
            for(Person* person: allPeople) {

                Sex sexIndex = person->getSex();
                Shading shadingIndex = person->getShading();
                if(sIndex == sexIndex) {
                    continue;
                }

                unsigned n = person->getHiddenStatesN();
                for(int i=0; i<n; ++i) {

                    for(int j=0; j<numbShades; ++j) {

                        LogVar aVal = pedigree->getAValue(person,i);
                        if(shadingIndex == j) {
                            _emissionProbs.at(sIndex).at(i).at(j) += aVal;
                        }
                        sums.at(i).at(j) += aVal;
                    }
                }
            }
        }

        for(int i=0; i<numbAlleles; ++i) {
            for(int j=0; j<numbShades; ++j) {
                _emissionProbs.at(sIndex).at(i).at(j) /= sums.at(i).at(j);
            }
        }
    }
}

LogVar PedigreeSoftEMOptimizer::getTransitionProb(const unordered_map<Person*,unsigned>& parents, Person* child, unsigned x) {

    pair<unsigned,unsigned> mXfX = _getMotherFatherIndices(parents);
    unsigned mX = mXfX.first;
    unsigned fX = mXfX.second;

    Sex sexIndex = child->getSex();

    LogVar ans = _transitionProbs.at(sexIndex).at(mX).at(fX).at(x);
    return ans;

}

LogVar PedigreeSoftEMOptimizer::getEmissionProb(Person* person, unsigned x) {
    Sex sexIndex = person->getSex();
    Shading shadingIndex = person->getShading();
    LogVar ans;
    ans = _emissionProbs.at(sexIndex).at(x).at(shadingIndex);
    return ans;
}

LogVar PedigreeSoftEMOptimizer::getRootProb(Pedigree* pedigree, Person* root, unsigned x) {
    return pedigree->getRootProb(root,x);
}

void PedigreeSoftEMOptimizer::EStep() {
    _calculateABCValues();
}

void PedigreeSoftEMOptimizer::MStep() {
    _updateRootProbs();
    _updateTransitionProbs();
    _updateEmissionProbs();
}



