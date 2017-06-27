#include "/Users/Eddie/hyperGraphEM/src/pedigreeParse/pedigreeParser.h"
#include "/Users/Eddie/hyperGraphEM/src/tests/testMain.h"


void allPedigreeParseTests() {
    
    PedigreeAllocator pedigreeAllocator;

    PedigreeParser parser("/Users/Eddie/kec-bot/app/pedigreeDataOLDBUTWORKS/1084LN.json");
    parser.printRawJSON();
    parser.parseJSON(pedigreeAllocator);
}
