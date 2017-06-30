#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraph.h"

void Node::_becomeParentOfFamily(Family* family) {
    _downFamilies.insert(family);
}

void Node::_becomeChildOfFamily(Family* family) {
    _upFamilies.insert(family);
}


unordered_set<Family*> Node::_getUpFamilies() const {
    return _upFamilies;
}

unordered_set<Family*> Node::_getDownFamilies() const {
    return _downFamilies;
}

unordered_set<Family*> Node::_getFamilies() const {
    unordered_set<Family*> allFamilies(_downFamilies.begin(),_downFamilies.end());
    allFamilies.insert(_upFamilies.begin(),_upFamilies.end());
    return allFamilies;
}

Data* Node::getData() const {
    return _data;
}


unordered_set<Family*> Node::getUpFamilies() const {
    return _getUpFamilies();
}

unordered_set<Family*> Node::getDownFamilies() const {
    return _getDownFamilies();
}

unordered_set<Family*> Node::getFamilies() const {
    return _getFamilies();
}

