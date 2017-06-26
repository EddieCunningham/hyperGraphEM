#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraph.h"

Family::Family(vector<Node*> parents, vector<Node*> children):
_parents(parents),
_children(children) {

    for(Node* parent: parents) {
        parent->_becomeParentOfFamily(this);
    }
    for(Node* child: children) {
        child->_becomeChildOfFamily(this);
    }
}


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


