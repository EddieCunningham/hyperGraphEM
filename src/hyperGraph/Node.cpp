#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraph.h"

void Node::_becomeParentOfFamily(Family* family) {
    _downFamilies.push_back(family);
}

void Node::_becomeChildOfFamily(Family* family) {
    _upFamilies.push_back(family);
}


vector<Family*> Node::_getUpFamilies() const {
    return _upFamilies;
}

vector<Family*> Node::_getDownFamilies() const {
    return _downFamilies;
}

vector<Family*> Node::_getFamilies() const {
    vector<Family*> allFamilies(_downFamilies.begin(),_downFamilies.end());
    allFamilies.insert(allFamilies.end(),_upFamilies.begin(),_upFamilies.end());
    return allFamilies;
}

Data* Node::_getData() const {
    return _data;
}

