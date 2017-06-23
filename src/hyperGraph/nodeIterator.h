#ifndef NODEITERATOR_H
#define NODEITERATOR_H

#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraph.h"
#include "/Users/Eddie/hyperGraphEM/src/messages/errorMessages.h"
#include <queue>
#include <unordered_set>

using namespace std;


// non-stl iterator that will
// do the selections needed on a hypergraph.
// will basically do a bfs from whatever starting nodes
// are given until there are none left to add
class NodeIterator {
    // friend class DirectedAcyclicHypergraph
    queue<Node*> _queue;
    unordered_set<Family*> _visitedFamilies;

    Node* _getFront() const;
    void _addFamilyFromNode(Family* f, Node* n);

public:
    NodeIterator() {}
    NodeIterator(const queue<Node*>& q, Family* startFam);
    NodeIterator(const vector<Node*>& v, Family* startFam);
    void operator=(const NodeIterator& other);
    Node* getCurrent() const;
    Node* next();
};

#endif







