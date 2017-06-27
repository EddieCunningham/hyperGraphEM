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

DAH* PedigreeAllocator::getDAH() {
    return _dah;
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

FamilyWrapper* PedigreeAllocator::allocateFamilyWrapper(int id, vector<Person*> parents, vector<Person*> children) {

    FamilyWrapper* familyWrapper = new FamilyWrapper(id,parents,children);
    _allFamilies[id] = familyWrapper;
    return familyWrapper;
}

DAH* PedigreeAllocator::allocateDAH(const vector<FamilyWrapper*>& families) {

    _dah = new DAH(families);
    return _dah;
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

void PedigreeAllocator::_deallocateFamilyWrappers() {

    for(pair<const int,FamilyWrapper*>& familyWrapper: _allFamilies) {
        delete familyWrapper.second;
    }
}

void PedigreeAllocator::_deallocateDAH() {

    delete _dah;
}


