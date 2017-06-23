#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraph.h"


vector<Node*> Family::_getParents() const {
    return _parents;
}

vector<Node*> Family::_getChildren() const {
    return _children;
}

vector<Node*> Family::_getNodes() const {
    vector<Node*> allNodes(_parents.begin(),_parents.end());
    allNodes.insert(allNodes.end(),_children.begin(),_children.end());
    return allNodes;
}
