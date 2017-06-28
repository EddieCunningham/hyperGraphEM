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

Data* Node::getData() const {
    return _data;
}


unordered_set<Family*> Node::getUpFamilies() const {
    vector<Family*> fams = _getUpFamilies();
    return unordered_set<Family*>(fams.begin(),fams.end());
}

unordered_set<Family*> Node::getDownFamilies() const {
    vector<Family*> fams = _getDownFamilies();
    return unordered_set<Family*>(fams.begin(),fams.end());
}

