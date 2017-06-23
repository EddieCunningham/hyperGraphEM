#ifndef HYPER_GRAPH_H
#define HYPER_GRAPH_H

#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/nodeIterator.h"
#include "/Users/Eddie/hyperGraphEM/src/messages/errorMessages.h"

class Data {
public:
    virtual int getData(string selector);
    virtual double getData(string selector);
};

class Node;
class Family;
class DirectedAcyclicHypergraph;

/* --------------------------------------- */

class Node {
    friend class NodeIterator;

    Family* _upFamily;
    vector<Family*> _downFamilies;
    Data* _data;

    Family* _getUpFamily() const;
    vector<Family*> _getDownFamilies() const;
    vector<Family*> _getFamilies() const;
    Data* _getData() const;

public:
    Node(): _data(nullptr) {}
    Node(Data* data): _data(data) {}
};

/* --------------------------------------- */

class Family {    
    friend class NodeIterator;

    vector<Node*> _parents;
    vector<Node*> _children;

    vector<Node*> _getParents() const;
    vector<Node*> _getChildren() const;
    vector<Node*> _getNodes() const;
public:
    Family(vector<Node*> parents, vector<Node*> children):_parents(parents),_children(children){}
};

/* --------------------------------------- */

class DirectedAcyclicHypergraph {
    vector<Family*> _families;

public:

    DirectedAcyclicHypergraph(const vector<Family*>& families): _families(families) {}

    // ^(n)
    // v(n)
    // e(n)
    // e(n^)
    // e(nv)
    NodeIterator getParents(Node* node) const;
    NodeIterator getChildren(Node* node) const;
    vector<Family*> getFamilies(Node* node) const;
    vector<Family*> getFamiliesIfParent(Node* node) const;
    vector<Family*> getFamiliesIfChild(Node* node) const;

    // n(e)
    // ^(e)
    // v(e)
    NodeIterator getNodesInFamily(Family* family) const;
    NodeIterator getParents(Family* family) const;
    NodeIterator getChildren(Family* family) const;

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

    // {}\n
    // {}\e
    // void excludeNode(NodeIterator& iterator, Node* node);
    // void excludeFamily(NodeIterator& iterator, Family* family);
};


ostream& operator <<(ostream& os, const Family* family);

#endif


