#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/nodeIterator.h"


NodeIterator::NodeIterator(const queue<Node*>& q, Family* startFam): _queue(q) {
    _visitedFamilies.insert(startFam);
}

NodeIterator(const vector<Node*>& v, Family* startFam) {
    _queue = queue<Node*>();
    for(Node* node: v) {
        _queue.push(node);
    }
    _visitedFamilies.insert(startFam);
}

void operator=(const NodeIterator& other) {
    _queue = other._queue;
    _visitedFamilies = other._visitedFamilies;
}


Node* NodeIterator::_getFront() const {
    if(_queue.size() == 0) {
        return nullptr;
    }
    return _queue.front();
}

Node* NodeIterator::getCurrent() const {
    return _getFront();
}

void NodeIterator::_addFamilyFromNode(Family* f, Node* n) {

    for(Node* node: f->_getNodes()) {

        if(node == n) {
            continue;
        }
        _queue.push(node);
    }
}

NodeIterator& NodeIterator::next() {
    // returns nullptr when at end

    Node* lastNode = _queue.front();
    _queue.pop();

    for(Family* family: lastNode->_getFamilies()) {

        if(_visitedFamilies.find(family) != _visitedFamilies.end()) {
            continue;
        }
        _addFamilyFromNode(family,lastNode);
        _visitedFamilies.insert(family);
    }

    return _getFront();

}
