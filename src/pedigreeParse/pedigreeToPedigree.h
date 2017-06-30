#ifndef PEDIGREETOPedigree_H
#define PEDIGREETOPedigree_H

#include "/Users/Eddie/hyperGraphEM/src/pedigreeParse/pedigreeParser.h"
#include "/Users/Eddie/hyperGraphEM/src/pedigreeParse/pedigreeAllocator.h"

class PedigreeToPedigree {

    Pedigree* _pedigree;
    PedigreeAllocator _allocator;
    PedigreeParser _parser;

public:
    PedigreeToPedigree(string filename): _parser(filename) {
        _parser.parseJSON(_allocator);
        _pedigree = _parser.getPedigree();
    }

    Pedigree* getPedigree() {
        return _pedigree;
    }

    Person* getPerson(int id) {
        return _allocator.getPerson(id);
    }

    /* TESTS */
    static void pedigreeToPedigreeTests();
    static void getPedigreeTests();
    static void getPersonTests();
};





#endif
