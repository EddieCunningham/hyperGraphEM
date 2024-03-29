#ifndef NODEITERATOR_H
#define NODEITERATOR_H

#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraph.h"
#include "/Users/Eddie/hyperGraphEM/src/messages/errorMessages.h"
#include <boost/algorithm/string.hpp>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;

class Node;
class Family;


// non-stl iterator that will
// do the selections needed on a hypergraph.
// will basically do a bfs from whatever starting nodes
// are given until there are none left to add
class NodeIterator {
    queue<pair<Node*,Family*>> _queue;
    unordered_set<Family*> _famsToBranchToFromCurrent;
    unordered_set<Family*> _visitedFamilies;

    Node* _getFrontNode() const;
    Family* _getFrontFamily() const;
    void _addFamilyFromNode(Family* f, Node* n);
    void _findWhereCurrentWillBranchTo();

    string _hash1() const;
    string _hash2() const;

public:
    NodeIterator() {
        _queue = queue<pair<Node*,Family*>>();
        _famsToBranchToFromCurrent = unordered_set<Family*>();
        _visitedFamilies = unordered_set<Family*>();
    }
    NodeIterator(const queue<pair<Node*,Family*>>& q, const unordered_set<Family*>& startFams, const unordered_set<Family*>& famsToSkip, bool keepFirstNode = false);
    NodeIterator(const unordered_set<Node*>& v, const unordered_set<Family*>& startFams, const unordered_set<Family*>& famsToSkip, bool keepFirstNode = false);
    void operator =(const NodeIterator& other);
    Node* getCurrent() const;
    Node* next();
    Family* getFamilyAddedFrom() const;
    unordered_set<Family*> getQueuedFamilies() const;
    unordered_set<Family*> getFamiliesToSkip() const;
    unordered_set<Node*> toSet() const;
    string getHash() const;

    static NodeIterator nodeIteratorFromOtherAndDirection(Node* node, Family* startFam, const NodeIterator& other, bool keepFirstNode = false);

    /* TESTS */
    static void NodeIteratorTests();
    static void operatorEqTests();
    static void getCurrentTests();
    static void getFamilyAddedFromTests();
    static void nextTests();
    static void getQueuedFamiliesTests();
    static void toSetTests();
    static void getHashTests();
};

class LoopHandler {

    NodeIterator _nodeIterator;
    vector<vector<Node*>> _dependentNodes;
    void _analyzeDependencies();

public:
    LoopHandler(const NodeIterator& nodeIterator, bool keepFirst):
    _nodeIterator(nodeIterator),
    _dependentNodes(vector<vector<Node*>>()) {
        if(keepFirst == false) {
            _nodeIterator.next();
        }    
        _analyzeDependencies();
    }

    vector<Node*> getDependentNodes(Node* node);

    /* TESTS */
    static void LoopHandlerTests();
    static void getDependentNodesTests();


};


#endif







