#ifndef HYPER_GRAPH_H
#define HYPER_GRAPH_H

#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/nodeIterator.h"
#include "/Users/Eddie/hyperGraphEM/src/messages/errorMessages.h"
#include <unordered_set>

using namespace std;

class Data {
    string _jsonifiedData;
public:
    Data(string jsonifiedData): _jsonifiedData(jsonifiedData) {}
    string getData() {
        return _jsonifiedData;
    }
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

    unordered_set<Family*> _upFamilies;
    unordered_set<Family*> _downFamilies;
    Data* _data;

    void _becomeParentOfFamily(Family* family);
    void _becomeChildOfFamily(Family* family);

protected:
    unordered_set<Family*> _getUpFamilies() const;
    unordered_set<Family*> _getDownFamilies() const;
    unordered_set<Family*> _getFamilies() const;

public:
    int id;

    Data* getData() const;
    Node(int id, Data* data): _data(data),id(id) {}

    unordered_set<Family*> getUpFamilies() const;
    unordered_set<Family*> getDownFamilies() const;
    unordered_set<Family*> getFamilies() const;

    /* TESTS */
    static void getDataTests();
    static void NodeTests();
    static void getUpFamiliesTests();
    static void getDownFamiliesTests();
    static void getFamiliesTests();
};

/* --------------------------------------- */

class Family {
    friend class NodeIterator;
    friend class DirectedAcyclicHypergraph;

    unordered_set<Node*> _parents;
    unordered_set<Node*> _children;

protected:
    unordered_set<Node*> _getParents() const;
    unordered_set<Node*> _getChildren() const;
    unordered_set<Node*> _getNodes() const;

protected:
    void _addParent(Node* parent);
    void _addChild(Node* child);

public:
    int id;

    Family(int id);
    Family(int id, unordered_set<Node*> parents, unordered_set<Node*> children);

    unordered_set<Node*> getParents() const;
    unordered_set<Node*> getChildren() const;
    unordered_set<Node*> getNodes() const;

    /* TESTS */
    static void FamilyTests();
    static void getParentsTests();
    static void getChildrenTests();
    static void getNodesTests();
};

/* --------------------------------------- */

class DirectedAcyclicHypergraph {
    unordered_set<Family*> _families;

protected:
    void _addFamily(Family* family);

public:

    DirectedAcyclicHypergraph() {}
    DirectedAcyclicHypergraph(const unordered_set<Family*>& families): _families(families) {}

    NodeIterator getAllNodesInIterator() const;
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
    // ↑(n),↓(n)\!(e,n)
    NodeIterator getAllFromFamilyExceptFromNode(Family* family, Node* node, bool keepFirstNode) const;
    NodeIterator getAllNodesExceptFromFamily(Family* family, Node* node, bool keepFirstNode) const;

    // ↑(n)
    // ↑(n)\!(e,n)
    NodeIterator getNodesUpFrom(Node* node, bool keepFirstNode) const;
    NodeIterator getNodesUpFromExceptFromFamily(Node* node, Family* family, bool keepFirstNode) const;

    // ↓(n)
    // ↓(n)\!(e,n)    
    NodeIterator getNodesDownFrom(Node* node, bool keepFirstNode = false) const;
    NodeIterator getNodesDownFromExceptFromFamily(Node* node, Family* family, bool keepFirstNode) const;



    /* TESTS */
    static void DirectedAcyclicHypergraphTests();
    static void getAllNodesInIteratorTests();
    static void getAllNodesTests();
    static void getAllFamiliesTests();
    static void getParentsTests();
    static void getChildrenTests();
    static void getFamiliesTests();
    static void getFamiliesIfParentTests();
    static void getFamiliesIfChildTests();
    static void getNodesInFamilyTests();
    static void getAllFromFamilyExceptFromNodeTests();
    static void getAllNodesExceptFromFamilyTests();
    static void getNodesUpFromTests();
    static void getNodesUpFromExceptFromFamilyTests();
    static void getNodesDownFromTests();
    static void getNodesDownFromExceptFromFamilyTests();
};


#endif


