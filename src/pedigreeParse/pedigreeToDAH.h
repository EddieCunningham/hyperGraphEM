#ifndef PEDIGREETODAH_H
#define PEDIGREETODAH_H

#include "/Users/Eddie/hyperGraphEM/src/pedigreeParse/pedigreeParser.h"
#include "/Users/Eddie/hyperGraphEM/src/pedigreeParse/pedigreeAllocator.h"

class pedigreeToDAH {

    DAH* _dah;
    PedigreeAllocator _allocator;
    PedigreeParser _parser;

public:
    pedigreeToDAH(string filename): _parser(filename) {
        _parser.parseJSON(_allocator);
        _dah = _parser.getDAH();
    }

    DAH* getDAH() {
        return _dah;
    }
};





#endif
