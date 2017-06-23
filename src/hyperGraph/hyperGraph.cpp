#include "hyperGraph.h"

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

Family::Family(vector<Node*> parents, vector<Node*> children):
_parents(parents),
_children(children) {
    for(Node* p: parents) {
        _nodes.push_back(p);
    }
    for(Node* c: children) {
        if(find(_nodes.begin(),_nodes.end(),c) != _nodes.end()) {
            string message = "Node can't be a parent and a child!";
            failWithMessage(__FILE__,__LINE__,message);
        }
        _nodes.push_back(c);
    }
}