#ifndef HYPER_GRAPH_H
#define HYPER_GRAPH_H

#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/nodeIterator.h"
#include "/Users/Eddie/hyperGraphEM/src/messages/errorMessages.h"
#include <vector>
#include <unordered_set>

using namespace std;

class Data {
    string _jsonifiedData;
public:
    Data(string jsonifiedData): _jsonifiedData(jsonifiedData) {}
};

class Node;
class Family;
class DirectedAcyclicHypergraph;
class NodeIterator;

/* --------------------------------------- */

class Node {
    friend class Family;
    friend class NodeIterator;
    friend class DirectedAcyclicHypergraph;

    vector<Family*> _upFamilies;
    vector<Family*> _downFamilies;
    Data* _data;

    void _becomeParentOfFamily(Family* family);
    void _becomeChildOfFamily(Family* family);

    vector<Family*> _getUpFamilies() const;
    vector<Family*> _getDownFamilies() const;
    vector<Family*> _getFamilies() const;

public:
    int id;

    Data* getData() const;
    Node(int id, Data* data): _data(data),id(id) {}
};

/* --------------------------------------- */

class Family {
    friend class NodeIterator;
    friend class DirectedAcyclicHypergraph;

    vector<Node*> _parents;
    vector<Node*> _children;

    vector<Node*> _getParents() const;
    vector<Node*> _getChildren() const;
    vector<Node*> _getNodes() const;

protected:
    void _addParent(Node* parent);
    void _addChild(Node* child);

public:
    int id;

    Family(int id);
    Family(int id, vector<Node*> parents, vector<Node*> children);
};

/* --------------------------------------- */

class DirectedAcyclicHypergraph {
    vector<Family*> _families;

protected:
    void _addFamily(Family* family);

public:

    DirectedAcyclicHypergraph() {}
    DirectedAcyclicHypergraph(const vector<Family*>& families): _families(families) {}

    unordered_set<Node*> getAllNodes() const;
    unordered_set<Family*> getAllFamilies() const;

    // ^(n)
    // v(n)
    // e(n)
    // e(n^)
    // e(nv)
    unordered_set<Node*> getParents(Node* node) const;
    unordered_set<Node*> getChildren(Node* node) const;
    unordered_set<Family*> getFamilies(Node* node) const;
    unordered_set<Family*> getFamiliesIfParent(Node* node) const;
    unordered_set<Family*> getFamiliesIfChild(Node* node) const;

    // n(e)
    // ^(e)
    // v(e)
    unordered_set<Node*> getNodesInFamily(Family* family) const;
    unordered_set<Node*> getParents(Family* family) const;
    unordered_set<Node*> getChildren(Family* family) const;

    // !(e,n)
    NodeIterator getAllFromFamilyExceptFromNode(Family* family, Node* node) const;

    // ↑(n)
    // ↑(n)\!(e,n)
    NodeIterator getNodesUpFrom(Node* node) const;
    NodeIterator getNodesUpFromExceptFromFamily(Node* node, Family* family) const;

    // ↓(n)
    // ↓(n)\!(e,n)    
    NodeIterator getNodesDownFrom(Node* node) const;
    NodeIterator getNodesDownFromExceptFromFamily(Node* node, Family* family) const;
};


#endif


