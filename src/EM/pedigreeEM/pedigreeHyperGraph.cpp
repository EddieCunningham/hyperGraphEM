#include "/Users/Eddie/hyperGraphEM/src/EM/pedigreeEM/pedigreeHyperGraph.h"
#include "/Users/Eddie/rapidjson/include/rapidjson/document.h"
#include "/Users/Eddie/rapidjson/include/rapidjson/writer.h"
#include "/Users/Eddie/rapidjson/include/rapidjson//prettywriter.h"
#include "/Users/Eddie/rapidjson/include/rapidjson/stringbuffer.h"
#include <boost/algorithm/string.hpp>


Person::Person(int id, Data* data): Node(id,data) {}

LogVar RootAncestorProbFunction::operator()(Node* node, unsigned x) {
    return _pedigree->getRootProb((Person*)node,x);
}

void Person::_initializeShading() {

    Data* data = getData();
    if(data == nullptr) {
        _shading = unshaded;
        return;
    }
    // Document _doc;
    // _doc.Parse(data);

    _shading = unshaded;
}

void Person::_initializeSexUsingMate() {

    unordered_set<Family*> downFamilies = getDownFamilies();
    for(Family* family: downFamilies) {

        unordered_set<Node*> parents = family->getParents();
        parents.erase(this);
        if(parents.size() != 1) {
            failWithMessage(__FILE__,__LINE__,"This should only have 1 parent");
        }
        Person* mate = (Person*)(*(parents.begin()));
        if(mate->getData() == nullptr) {
            failWithMessage(__FILE__,__LINE__,"Should have some data for this person!");
        }
        Sex sex = mate->getSex();
        if(sex == female) {
            _sex = male;
        }
        else if(sex == male) {
            _sex = female;
        }
        else if(sex == unknown) {
            _sex = unknown;
        }
        else {
            failWithMessage(__FILE__,__LINE__,"Invalid sex");
        }
        break;
    }
}

void Person::_initializeSexFromData() {
    rapidjson::Document _doc;
    Data* data = getData();
    string jsonifiedData = data->getData();
    _doc.Parse(jsonifiedData.c_str());
    string shape = _doc["shapeName"].GetString();
    if(shape == "circle") {
        _sex = female;
    }
    else if(shape == "square") {
        _sex = male;
    }
    else if(shape == "diamond") {
        _sex = unknown;
    }
    else {
        failWithMessage(__FILE__,__LINE__,"Invalid shape!");
    }
}


void Person::_initializeSex() {

    Data* data = getData();
    if(data == nullptr) {
        _initializeSexUsingMate();
    }
    else {
        _initializeSexFromData();
    }

}

void Person::_initializeSexAndShading() {
    _initializeShading();
    _initializeSex();
}


Shading Person::getShading() {
    if(_shading == NUMB_SHADING) {
        _initializeSexAndShading();
    }
    return _shading;
}


Sex Person::getSex() {

    if(_sex == NUMB_SEXES) {
        _initializeSexAndShading();
    }
    return _sex;
}

int Person::getHiddenStatesN() {
    return NUMB_ALLELES;
}

int Person::getObservedStatesN() {
    return NUMB_SHADING;
}

/* ------------------------------------ */


/* ------------------------------------ */

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
