#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/nodeIterator.h"


NodeIterator::NodeIterator(const queue<Node*>& q, Family* startFam): _queue(q) {
    _visitedFamilies.insert(startFam);
}


Node* NodeIterator::begin() {
    Node* toReturn = _queue.front();
    _branchFromNode(toReturn);
    _queue.pop();
}

NodeIterator& NodeIterator::operator++() {
    
}

bool NodeIterator::atEnd() {

}
