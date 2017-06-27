#ifndef PEDIGREEALLOCATOR_H
#define PEDIGREEALLOCATOR_H

#include "/Users/Eddie/hyperGraphEM/src/EM/pedigreeEM/hyperGraphDelegate.h"
using namespace std;
#include <vector>

class PedigreeAllocator {

    vector<Data*> _allData;
    vector<Person*> _allNodes;
    vector<FamilyWrapper*> _allFamilies;
    vector<DAH*> _allDAHs;

public:
    PedigreeAllocator() {}

    Data* allocateData(string jsonifiedData);
    Person* allocatePerson(int id, Data* data);
    FamilyWrapper* allocateFamilyWrapper(int id, vector<Person*> parents, vector<Person*> children);
    DAH* allocateDAH(const vector<FamilyWrapper*>& families);

    void deallocateData();
    void deallocatePeople();
    void deallocateFamilyWrappers();
    void deallocateDAHs();
};













#endif
