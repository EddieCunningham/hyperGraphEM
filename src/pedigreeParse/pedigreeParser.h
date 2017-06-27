#ifndef PEDIGREEPARSER_H
#define PEDIGREEPARSER_H

#include <iostream>
#include <vector>
#include <fstream>

#include "/Users/Eddie/hyperGraphEM/src/EM/pedigreeEM/hyperGraphDelegate.h"
#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraph.h"
#include "/Users/Eddie/hyperGraphEM/src/pedigreeParse/pedigreeAllocator.h"
#include <boost/algorithm/string/replace.hpp>
#include "/Users/Eddie/rapidjson/include/rapidjson/document.h"
#include "/Users/Eddie/rapidjson/include/rapidjson/writer.h"
#include "/Users/Eddie/rapidjson/include/rapidjson/stringbuffer.h"

using namespace rapidjson;
using namespace std;

class PedigreeParser {

    Document _doc;
    string _filename;

    DirectedAcyclicHypergraph* _dah;
    DAH* _dahWrapper;

public:

    void printRawJSON();
    PedigreeParser(string filename);
    void parseJSON(PedigreeAllocator& pedigreeAllocator);

    
};






#endif


