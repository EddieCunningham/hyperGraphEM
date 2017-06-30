#ifndef PEDIGREEPARSER_H
#define PEDIGREEPARSER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>

#include "/Users/Eddie/hyperGraphEM/src/EM/pedigreeEM/pedigreeHyperGraph.h"
#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraph.h"
#include "/Users/Eddie/hyperGraphEM/src/pedigreeParse/pedigreeAllocator.h"
#include <boost/algorithm/string/replace.hpp>
#include "/Users/Eddie/rapidjson/include/rapidjson/document.h"
#include "/Users/Eddie/rapidjson/include/rapidjson/writer.h"
#include "/Users/Eddie/rapidjson/include/rapidjson//prettywriter.h"
#include "/Users/Eddie/rapidjson/include/rapidjson/stringbuffer.h"
#include <boost/algorithm/string.hpp>

using namespace rapidjson;
using namespace std;

class PedigreeParser {

    Document _doc;
    string _filename;

    DAH* _dah;
    void _setDAH(DAH* dah);

    unordered_map<string,vector<int>> _intFamilies;

    void _addPerson(int Id, string jsonifiedData, PedigreeAllocator& pedigreeAllocator);
    void _addFamily(int mateA_, int mateB_, const vector<int>& children);
    unordered_map<int,vector<int>> _parseMateKids(string mateKids);
    pair<int,int> _parseParentsString(string parentString);
    void _establishRelationships(int Id, string jsonifiedData, string mateKids, PedigreeAllocator& pedigreeAllocator);
    void _finalizeFamilies(PedigreeAllocator& pedigreeAllocator);
    

public:

    PedigreeParser(string filename);
    void printRawJSON();
    void parseJSON(PedigreeAllocator& pedigreeAllocator);
    DAH* getDAH();

    /* TESTS */
    static void PedigreeParserTests();
    static void printRawJSONTests();
    static void parseJSONTests();
    static void getDAHTests();

};






#endif


