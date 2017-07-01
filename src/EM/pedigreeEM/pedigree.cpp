#include "/Users/Eddie/hyperGraphEM/src/EM/pedigreeEM/pedigreeHyperGraph.h"



void Pedigree::calcABCVals() {

}

LogVar Pedigree::getAValue(Person* node, int x) {
    return LogVar();
}

LogVar Pedigree::getBValue(NuclearFamily* family, const unordered_map<Person*,unsigned int>& X) {
    return LogVar();
}

LogVar Pedigree::getCValue(NuclearFamily* family, Person* child, const unordered_map<Person*,unsigned int>& X, int x) {
    return LogVar();
}


void Pedigree::updateRootProb(Person* root, int x, LogVar val) {

    if(_rootProbs.find(root) == _rootProbs.end()) {
        failWithMessage(__FILE__,__LINE__,"invalid root!");
    }
    if(x >= _rootProbs.at(root).size()) {
        failWithMessage(__FILE__,__LINE__,"invalid index!");
    }
    _rootProbs.at(root).at(x) = val;
}

LogVar Pedigree::getRootProb(Person* root, int x) {
    if(_rootProbs.find(root) == _rootProbs.end()) {
        failWithMessage(__FILE__,__LINE__,"invalid root!");
    }
    if(x >= _rootProbs.at(root).size()) {
        failWithMessage(__FILE__,__LINE__,"invalid index!");
    }
    return _rootProbs.at(root).at(x);
}

unordered_map<Person*,vector<LogVar>> Pedigree::getRootProbs() {
    return _rootProbs;
}

unordered_set<Person*> Pedigree::getAllNodes() const {
    return Person::nodeToPerson(DirectedAcyclicHypergraph::getAllNodes());
}

unordered_set<NuclearFamily*> Pedigree::getAllFamilies() const {
    return NuclearFamily::familyToNuclearFamily(DirectedAcyclicHypergraph::getAllFamilies());
}

unordered_set<Person*> Pedigree::getParents(Person* node) const {
    return Person::nodeToPerson(DirectedAcyclicHypergraph::getParents(node));
}

unordered_set<Person*> Pedigree::getChildren(Person* node) const {
    return Person::nodeToPerson(DirectedAcyclicHypergraph::getChildren(node));
}

unordered_set<NuclearFamily*> Pedigree::getFamilies(Person* node) const {
    return NuclearFamily::familyToNuclearFamily(DirectedAcyclicHypergraph::getFamilies(node));
}

unordered_set<NuclearFamily*> Pedigree::getFamiliesIfParent(Person* node) const {
    return NuclearFamily::familyToNuclearFamily(DirectedAcyclicHypergraph::getFamiliesIfParent(node));
}

unordered_set<NuclearFamily*> Pedigree::getFamiliesIfChild(Person* node) const {
    return NuclearFamily::familyToNuclearFamily(DirectedAcyclicHypergraph::getFamiliesIfChild(node));
}

unordered_set<Person*> Pedigree::getNodesInFamily(NuclearFamily* family) const {
    return Person::nodeToPerson(DirectedAcyclicHypergraph::getNodesInFamily(family));
}

unordered_set<Person*> Pedigree::getParents(NuclearFamily* family) const {
    return Person::nodeToPerson(DirectedAcyclicHypergraph::getParents(family));
}

unordered_set<Person*> Pedigree::getChildren(NuclearFamily* family) const {
    return Person::nodeToPerson(DirectedAcyclicHypergraph::getChildren(family));
}