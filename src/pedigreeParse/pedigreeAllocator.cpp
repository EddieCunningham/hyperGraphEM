#include "/Users/Eddie/hyperGraphEM/src/pedigreeParse/pedigreeAllocator.h"

Person* PedigreeAllocator::getPerson(int id) {
    if(_allPeople.find(id) == _allPeople.end()) {
        return nullptr;
    }
    return _allPeople.at(id);
}

Family* PedigreeAllocator::getFamily(int id) {
    if(_allFamilies.find(id) == _allFamilies.end()) {
        return nullptr;
    }
    return _allFamilies.at(id);
}

Pedigree* PedigreeAllocator::getPedigree() {
    return _pedigree;
}

Data* PedigreeAllocator::allocateData(string jsonifiedData) {

    Data* data = new Data(jsonifiedData);
    _allData.push_back(data);
    return data;
}

Person* PedigreeAllocator::allocatePerson(int id, Data* data) {

    Person* person = new Person(id,data);
    _allPeople[id] = person;
    return person;
}

NuclearFamily* PedigreeAllocator::allocateNuclearFamily(int id, unordered_set<Person*> parents, unordered_set<Person*> children) {

    NuclearFamily* NuclearFamily = new class NuclearFamily(id,parents,children);
    _allFamilies[id] = NuclearFamily;
    return NuclearFamily;
}

Pedigree* PedigreeAllocator::allocatePedigree(const unordered_set<NuclearFamily*>& families) {

    _pedigree = new Pedigree(families);
    return _pedigree;
}

void PedigreeAllocator::_deallocateData() {

    for(Data* data: _allData) {
        delete data;
    }
}

void PedigreeAllocator::_deallocatePeople() {

    for(pair<const int,Person*>& idPerson: _allPeople) {
        delete idPerson.second;
    }
}

void PedigreeAllocator::_deallocateNuclearFamilys() {

    for(pair<const int,NuclearFamily*>& NuclearFamily: _allFamilies) {
        delete NuclearFamily.second;
    }
}

void PedigreeAllocator::_deallocatePedigree() {

    delete _pedigree;
}


