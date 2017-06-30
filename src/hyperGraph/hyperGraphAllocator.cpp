#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraphAllocator.h"


Data* HyperGraphAllocator::allocateData(string jsonifiedData) {

    Data* data = new Data(jsonifiedData);
    _allData.insert(data);
    return data;
}

Node* HyperGraphAllocator::allocateNode(int id, Data* data) {

    Node* node = new Node(id,data);
    _allNodes.insert(node);
    return node;
}

Family* HyperGraphAllocator::allocateFamily(int id, unordered_set<Node*> parents, unordered_set<Node*> children) {

    Family* family = new Family(id,parents,children);
    _allFamilies.insert(family);
    return family;
}

DirectedAcyclicHypergraph* HyperGraphAllocator::allocateDAH(const unordered_set<Family*>& families) {

    _dah = new DirectedAcyclicHypergraph(families);
    return _dah;
}

void HyperGraphAllocator::deallocateData() {

    for(Data* data: _allData) {
        delete data;
    }
}

void HyperGraphAllocator::deallocateNodes() {

    for(Node* node: _allNodes) {
        delete node;
    }
}

void HyperGraphAllocator::deallocateFamilies() {

    for(Family* family: _allFamilies) {
        delete family;
    }
}

void HyperGraphAllocator::deallocateDAH() {

    delete _dah;
}


