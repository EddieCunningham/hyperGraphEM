#ifndef HYPERGRAPHALLOCATOR_H
#define HYPERGRAPHALLOCATOR_H

#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraph.h"
#include <vector>
using namespace std;



class HyperGraphAllocator {

    vector<Data*> _allData;
    vector<Node*> _allNodes;
    vector<Family*> _allFamilies;
    DirectedAcyclicHypergraph* _dah;

public:
    HyperGraphAllocator() {}

    Data* allocateData(string jsonifiedData);
    Node* allocateNode(int id, Data* data);
    Family* allocateFamily(int id, vector<Node*> parents, vector<Node*> children);
    DirectedAcyclicHypergraph* allocateDAH(const vector<Family*>& families);

    void deallocateData();
    void deallocateNodes();
    void deallocateFamilies();
    void deallocateDAH();
};









#endif
