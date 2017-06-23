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
    vector<int> _cycleNumbers;
    Data* _data;

    vector<Node*> _getParents();

    // _getChildren() returns all children of node
    // _getChildren(vector<Node*> mates) returns all children in families that node and mate[i] are in
    // _getChildren(vector<Family*> families) returns all children that mate is a parent of in families
    vector<Node*> _getChildren();
    vector<Node*> _getChildren(vector<Node*> mates);
    vector<Node*> _getChildren(vector<Family*> families);

    // _getMates() returns all children of node
    // _getMates(vector<Node*> mates) returns all mates in families that node and mate[i] are in
    // _getMates(vector<Family*> families) returns all mates that mate is a parent of in families
    vector<Node*> _getMates();
    vector<Node*> _getMates(vector<Node*> mates);
    vector<Node*> _getMates(vector<Family*> families);

    // _getFamilies() will return all families that node is in
    // _getUpFamily() will return the family that node is a child in
    // _getFamilies(vector<Node*> mates) will return the families that node and mate[i] are parents of
    // _getFamilies(vector<Node*> children) will return families where node is a parent of node[i]
    vector<Family*> _getFamilies();
    vector<Family*> _getUpFamily();
    vector<Family*> _getFamilies(vector<Node*> mates);
    vector<Family*> _getFamilies(vector<Node*> children);

    bool _isRoot();
    bool _isLeaf();
    bool _inCycle();

public:
    Node(): _data(nullptr) {}
    Node(Data* data): _data(data) {}
};

/* --------------------------------------- */

class Family {    
    friend class NodeIterator;

    vector<Node*> _nodes;
    vector<Node*> _parents;
    vector<Node*> _children;

    void _insertNode(Node* node, bool isParent);
    vector<Node*> _getParents();
    vector<Node*> _getChildren();
public:
    Family(vector<Node*> parents, vector<Node*> children);
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


