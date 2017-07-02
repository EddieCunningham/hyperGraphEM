#include "/Users/Eddie/hyperGraphEM/src/tests/testMain.h"
#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraph.h"
#include "/Users/Eddie/hyperGraphEM/src/pedigreeParse/pedigreeToPedigree.h"
#include "/Users/Eddie/hyperGraphEM/src/messages/errorMessages.h"
#include "/Users/Eddie/hyperGraphEM/src/helper/nestedLoop.h"
#include "/Users/Eddie/hyperGraphEM/src/EM/pedigreeEM/pedigreeHyperGraph.h"
#include "/Users/Eddie/hyperGraphEM/src/EM/pedigreeEM/softEM.h"
#include "/Users/Eddie/hyperGraphEM/src/EM/pedigreeEM/softEM.h"
#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/forwardsBackwards.h"
#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraphAllocator.h"
#include "/Users/Eddie/hyperGraphEM/src/logVar/logVar.h"
#include "/Users/Eddie/hyperGraphEM/src/helper/nestedLoop.h"
#include "/Users/Eddie/hyperGraphEM/src/pedigreeParse/pedigreeAllocator.h"

void allTests() {

    Person::PersonTests();
    NuclearFamily::NuclearFamilyTests();
    Pedigree::PedigreeTests();
    PedigreeSoftEMOptimizer::PedigreeSoftEMOptimizerTests();
    PedigreeEMModel::PedigreeEMModelTests();
    MapIterator<Node*>::MapIteratorTests();
    FowrardsBackwards::FowrardsBackwardsTests();
    Node::NodeTests();
    Family::FamilyTests();
    DirectedAcyclicHypergraph::DirectedAcyclicHypergraphTests();
    HyperGraphAllocator::HyperGraphAllocatorTests();
    NodeIterator::NodeIteratorTests();
    LoopHandler::LoopHandlerTests();
    LogVar::LogVarTests();
    PedigreeAllocator::PedigreeAllocatorTests();
    PedigreeParser::PedigreeParserTests();
    PedigreeToPedigree::pedigreeToPedigreeTests();
    

    // allNestedLoopTests();
    // allLogVarTests();
    // allDAHTests();
    // allPedigreeParseTests();

    
    // allDAHEMTests();
    // allForwardsBackwardsTests();
    

}
