#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraph.h"



ostream& operator <<(ostream& os, const Family* family) {
    cout << "Parents: {";
    int i=0;
    for(Node* node: _parents) {
        cout << node;
        if(i < _parents.size()-1) {
            cout << ",";
        }
        ++i;
    }
    cout << "}  Children: {";
    i=0;
    for(Node* node: _children) {
        cout << node;
        if(i < _children.size()-1) {
            cout << ",";
        }
        ++i;
    }
}
