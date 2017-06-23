#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraph.h"


NodeIterator DirectedAcyclicHypergraph::getParents(Node* node) const {
    Family* family = node->_getUpFamily();
    vector<Node*> parents = family->_getParents();
    NodeIterator iterator(parents,family);
    return iterator;
}

NodeIterator DirectedAcyclicHypergraph::getChildren(Node* node) const {
    Family* family = node->_getUpFamily();
    vector<Node*> children = family->_getChildren();
    NodeIterator iterator(children,family);
    return iterator;
}

vector<Family*> DirectedAcyclicHypergraph::getFamilies(Node* node) const {
    return vector<Family*>({});
}

vector<Family*> DirectedAcyclicHypergraph::getFamiliesIfParent(Node* node) const {
    return vector<Family*>({});
}
vector<Family*> DirectedAcyclicHypergraph::getFamiliesIfChild(Node* node) const {
    return vector<Family*>({});
}
NodeIterator DirectedAcyclicHypergraph::getNodesInFamily(Family* family) const {
    return NodeIterator();
}
NodeIterator DirectedAcyclicHypergraph::getParents(Family* family) const {
    return NodeIterator();
}
NodeIterator DirectedAcyclicHypergraph::getChildren(Family* family) const {
    return NodeIterator();
}
NodeIterator DirectedAcyclicHypergraph::getAllFromFamilyExceptFromNode(Family* family, Node* node) const {
    return NodeIterator();
}
NodeIterator DirectedAcyclicHypergraph::getNodesUpFrom(Node* node) const {
    return NodeIterator();
}
NodeIterator DirectedAcyclicHypergraph::getNodesUpFromExceptFromFamily(Node* node, Family* family) const {
    return NodeIterator();
}
NodeIterator DirectedAcyclicHypergraph::getNodesDownFrom(Node* node) const {
    return NodeIterator();
}
NodeIterator DirectedAcyclicHypergraph::getNodesDownFromExceptFromFamily(Node* node, Family* family) const {
    return NodeIterator();
}


