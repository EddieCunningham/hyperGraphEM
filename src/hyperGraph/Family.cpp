#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraph.h"

Family::Family(int id): id(id){}

void Family::_addParent(Node* parent) {
    _parents.insert(parent);
    parent->_becomeParentOfFamily(this);
}

void Family::_addChild(Node* child) {
    _children.insert(child);
    child->_becomeChildOfFamily(this);
}


Family::Family(int id, unordered_set<Node*> parents, unordered_set<Node*> children):
id(id),
_parents(parents),
_children(children) {

    for(Node* parent: parents) {
        parent->_becomeParentOfFamily(this);
    }
    for(Node* child: children) {
        child->_becomeChildOfFamily(this);
    }
}


unordered_set<Node*> Family::_getParents() const {
    return _parents;
}

unordered_set<Node*> Family::_getChildren() const {
    return _children;
}

unordered_set<Node*> Family::_getNodes() const {
    unordered_set<Node*> allNodes(_parents.begin(),_parents.end());
    allNodes.insert(_children.begin(),_children.end());
    return allNodes;
}



unordered_set<Node*> Family::getParents() const {
    return _getParents();
}

unordered_set<Node*> Family::getChildren() const {
    return _getChildren();
}

unordered_set<Node*> Family::getNodes() const {
    return _getNodes();
}


