#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraph.h"

Family* Node::_getUpFamily() const {
    return _upFamily;
}

vector<Family*> Node::_getDownFamilies() const {
    return _downFamilies;
}

vector<Family*> Node::_getFamilies() const {
    vector<Family*> allFamilies(_downFamilies.begin(),_downFamilies.end());
    allFamilies.push_back(_upFamily);
    return allFamilies;
}

Data* Node::_getData() const {
    return _data;
}

