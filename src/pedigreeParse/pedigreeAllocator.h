#ifndef PEDIGREEALLOCATOR_H
#define PEDIGREEALLOCATOR_H

#include "/Users/Eddie/hyperGraphEM/src/EM/pedigreeEM/pedigreeHyperGraph.h"
using namespace std;
#include <vector>
#include <unordered_set>


class PedigreeAllocator {

    vector<Data*> _allData;
    unordered_map<int,Person*> _allPeople;
    unordered_map<int,NuclearFamily*> _allFamilies;
    Pedigree* _pedigree;

    void _deallocateData();
    void _deallocatePeople();
    void _deallocateNuclearFamilys();
    void _deallocatePedigree();

public:
    PedigreeAllocator() {}

    Person* getPerson(int id);
    Family* getFamily(int id);
    Pedigree* getPedigree();

    Data* allocateData(string jsonifiedData);
    Person* allocatePerson(int id, Data* data);
    NuclearFamily* allocateNuclearFamily(int id, unordered_set<Person*> parents, unordered_set<Person*> children);
    Pedigree* allocatePedigree(const unordered_set<NuclearFamily*>& families);

    ~PedigreeAllocator() {
        _deallocateData();
        _deallocatePeople();
        _deallocateNuclearFamilys();
        _deallocatePedigree();
    }

    /* TESTS */
    static void PedigreeAllocatorTests();
    static void getPersonTests();
    static void getFamilyTests();
    static void getDAHTests();
    static void allocateDataTests();
    static void allocatePersonTests();
    static void allocateNuclearFamilyTests();
    static void allocateDAHTests();
};













#endif
