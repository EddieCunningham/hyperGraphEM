#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/nodeIterator.h"


NodeIterator::NodeIterator(const queue<Node*>& q, const unordered_set<Family*>& startFams, const unordered_set<Family*>& famsToSkip, bool keepFirstNode): 
_queue(q) {

    _famsToBranchToFromCurrent = unordered_set<Family*>();
    _famsToBranchToFromCurrent.insert(startFams.begin(),startFams.end());

    _visitedFamilies = unordered_set<Family*>();
    _visitedFamilies.insert(famsToSkip.begin(),famsToSkip.end());

    if(!keepFirstNode) {
        next();
    }
}

NodeIterator::NodeIterator(const unordered_set<Node*>& v, const unordered_set<Family*>& startFams, const unordered_set<Family*>& famsToSkip, bool keepFirstNode) {

    _famsToBranchToFromCurrent = unordered_set<Family*>();
    _famsToBranchToFromCurrent.insert(startFams.begin(),startFams.end());

    _visitedFamilies = unordered_set<Family*>();
    _visitedFamilies.insert(famsToSkip.begin(),famsToSkip.end());

    _queue = queue<Node*>();
    for(Node* node: v) {
        _queue.push(node);
    }

    if(!keepFirstNode) {
        next();
    }
}

void NodeIterator::operator =(const NodeIterator& other) {
    _queue = other._queue;
    _visitedFamilies = other._visitedFamilies;
    _famsToBranchToFromCurrent = other._famsToBranchToFromCurrent;
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

        unordered_set<Family*> fams = node->getFamilies();
        bool foundFlag = false;
        for(Family* fam: fams) {
            if(_visitedFamilies.find(fam) != _visitedFamilies.end()) {
                foundFlag = true;
                break;
            }
        }

        if(foundFlag || node == n) {
            continue;
        }
        _queue.push(node);
    }
}

void NodeIterator::_findWhereCurrentWillBranchTo() {

    _famsToBranchToFromCurrent = unordered_set<Family*>();

    Node* currentNode = _getFront();
    if(currentNode == nullptr) {
        return;
    }
    for(Family* family: currentNode->_getFamilies()) {

        if(_visitedFamilies.find(family) != _visitedFamilies.end()) {
            continue;
        }
        _famsToBranchToFromCurrent.insert(family);
    }
}

Node* NodeIterator::next() {
    // returns nullptr when at end

    Node* lastNode = _getFront();
    if(lastNode == nullptr) {
        return nullptr;
    }
    _queue.pop();

    for(Family* family: _famsToBranchToFromCurrent) {
        _addFamilyFromNode(family,lastNode);
        _visitedFamilies.insert(family);
    }

    _findWhereCurrentWillBranchTo();

    return _getFront();

}

unordered_set<Family*> NodeIterator::getQueuedFamilies() const {
    return _famsToBranchToFromCurrent;
}

unordered_set<Node*> NodeIterator::toSet() const {

    NodeIterator aCopy = *this;
    unordered_set<Node*> ans = unordered_set<Node*>();

    for(Node* current = aCopy.getCurrent(); current != nullptr; current = aCopy.next()) {
        ans.insert(current);
    }

    return ans;
}


string NodeIterator::_hash1() const {

    unordered_set<Node*> asSet = toSet();

    vector<int> allIds = vector<int>();
    for(Node* node: asSet) {
        allIds.push_back(node->id);
    }
    
    sort(allIds.begin(),allIds.end());

    string hash = "__NodeIterator{";
    for(int i=0; i<allIds.size(); ++i) {
        int id = allIds.at(i);
        hash += to_string(id);
        if(i < allIds.size()-1) {
            hash += ",";
        }
    }
    hash += "}__";
    return hash;
}


string NodeIterator::_hash2() const {

    // only need to store the initial queue and the initial visited families
    queue<Node*> queueCopy = _queue;
    unordered_set<Family*> visitedFamiliesCopy = _visitedFamilies;
    unordered_set<Family*> famsToBranchToCopy = _famsToBranchToFromCurrent;


    vector<int> initialQueueIds = vector<int>();
    while(!queueCopy.empty()) {
        Node* node = queueCopy.front();
        initialQueueIds.push_back(node->id);
        queueCopy.pop();
    }
    sort(initialQueueIds.begin(),initialQueueIds.end());

    vector<int> visitedFamIds = vector<int>();
    for(Family* family: visitedFamiliesCopy) {
        visitedFamIds.push_back(family->id);
    }
    sort(visitedFamIds.begin(),visitedFamIds.end());

    vector<int> nextBranchIds = vector<int>();
    for(Family* family: famsToBranchToCopy) {
        nextBranchIds.push_back(family->id);
    }
    sort(nextBranchIds.begin(),nextBranchIds.end());


    string hash = "__NodeIterator{_queue:{";
    for(int i=0; i<initialQueueIds.size(); ++i) {
        int id = initialQueueIds.at(i);
        hash += to_string(id);
        if(i < initialQueueIds.size()-1) {
            hash += ",";
        }
    }
    hash += "},_visitedFamilies:{";
    for(int i=0; i<visitedFamIds.size(); ++i) {
        int id = visitedFamIds.at(i);
        hash += to_string(id);
        if(i < visitedFamIds.size()-1) {
            hash += ",";
        }
    }   
    hash += "},_famsToBranchToFromCurrent:{";
    for(int i=0; i<nextBranchIds.size(); ++i) {
        int id = nextBranchIds.at(i);
        hash += to_string(id);
        if(i < nextBranchIds.size()-1) {
            hash += ",";
        }
    }     
    hash += "}}__";
    return hash;

}


string NodeIterator::getHash() const {
    return _hash1();
    // return _hash2();
}

