#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraphAllocator.h"


Data* HyperGraphAllocator::allocateData(string jsonifiedData) {

    Data* data = new Data(jsonifiedData);
    _allData.push_back(data);
    return data;
}

Node* HyperGraphAllocator::allocateNode(int id, Data* data) {

    Node* node = new Node(id,data);
    _allNodes.push_back(node);
    return node;
}

Family* HyperGraphAllocator::allocateFamily(int id, vector<Node*> parents, vector<Node*> children) {

    Family* family = new Family(id,parents,children);
    _allFamilies.push_back(family);
    return family;
}

DirectedAcyclicHypergraph* HyperGraphAllocator::allocateDAH(const vector<Family*>& families) {

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


