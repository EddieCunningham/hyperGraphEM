#include "/Users/Eddie/hyperGraphEM/src/pedigreeParse/pedigreeAllocator.h"


Data* PedigreeAllocator::allocateData(string jsonifiedData) {

    Data* data = new Data(jsonifiedData);
    _allData.push_back(data);
    return data;
}

Person* PedigreeAllocator::allocatePerson(int id, Data* data) {

    Person* person = new Person(id,data);
    _allNodes.push_back(person);
    return person;
}

FamilyWrapper* PedigreeAllocator::allocateFamilyWrapper(int id, vector<Person*> parents, vector<Person*> children) {

    FamilyWrapper* familyWrapper = new FamilyWrapper(id,parents,children);
    _allFamilies.push_back(familyWrapper);
    return familyWrapper;
}

DAH* PedigreeAllocator::allocateDAH(const vector<FamilyWrapper*>& families) {

    DAH* dah = new DAH(families);
    _allDAHs.push_back(dah);
    return dah;
}

void PedigreeAllocator::deallocateData() {

    for(Data* data: _allData) {
        delete data;
    }
}

void PedigreeAllocator::deallocatePeople() {

    for(Person* Person: _allNodes) {
        delete Person;
    }
}

void PedigreeAllocator::deallocateFamilyWrappers() {

    for(FamilyWrapper* familyWrapper: _allFamilies) {
        delete familyWrapper;
    }
}

void PedigreeAllocator::deallocateDAHs() {

    for(DAH* dah: _allDAHs) {
        delete dah;
    }
}


