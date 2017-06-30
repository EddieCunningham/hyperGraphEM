#ifndef HYPERGRAPHALLOCATOR_H
#define HYPERGRAPHALLOCATOR_H

#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraph.h"
#include <unordered_set>
using namespace std;



class HyperGraphAllocator {

    unordered_set<Data*> _allData;
    unordered_set<Node*> _allNodes;
    unordered_set<Family*> _allFamilies;
    DirectedAcyclicHypergraph* _dah;

public:
    HyperGraphAllocator() {}

    Data* allocateData(string jsonifiedData);
    Node* allocateNode(int id, Data* data);
    Family* allocateFamily(int id, unordered_set<Node*> parents, unordered_set<Node*> children);
    DirectedAcyclicHypergraph* allocateDAH(const unordered_set<Family*>& families);

    void deallocateData();
    void deallocateNodes();
    void deallocateFamilies();
    void deallocateDAH();

    /* TESTS */
    static void HyperGraphAllocatorTests();
    static void allocateDataTests();
    static void allocateNodeTests();
    static void allocateFamilyTests();
    static void allocateDAHTests();
    static void deallocateDataTests();
    static void deallocateNodesTests();
    static void deallocateFamiliesTests();
    static void deallocateDAHTests();
};









#endif
