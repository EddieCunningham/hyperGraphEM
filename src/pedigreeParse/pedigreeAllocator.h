#ifndef PEDIGREEALLOCATOR_H
#define PEDIGREEALLOCATOR_H

#include "/Users/Eddie/hyperGraphEM/src/EM/pedigreeEM/pedigreeHyperGraph.h"
using namespace std;
#include <vector>

class PedigreeAllocator {

    vector<Data*> _allData;
    unordered_map<int,Person*> _allPeople;
    unordered_map<int,FamilyWrapper*> _allFamilies;
    DAH* _dah;

    void _deallocateData();
    void _deallocatePeople();
    void _deallocateFamilyWrappers();
    void _deallocateDAH();

public:
    PedigreeAllocator() {}

    Person* getPerson(int id);
    Family* getFamily(int id);
    DAH* getDAH();

    Data* allocateData(string jsonifiedData);
    Person* allocatePerson(int id, Data* data);
    FamilyWrapper* allocateFamilyWrapper(int id, vector<Person*> parents, vector<Person*> children);
    DAH* allocateDAH(const vector<FamilyWrapper*>& families);



    ~PedigreeAllocator() {
        _deallocateData();
        _deallocatePeople();
        _deallocateFamilyWrappers();
        _deallocateDAH();
    }
};













#endif
