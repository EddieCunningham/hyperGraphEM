#include <iostream>
#include <unordered_set>
#include "hyperGraph.h"

void testNodeInit() {

    Node a_;
    Node b_;
    Node c_;

    Node *a = &a_;
    Node *b = &b_;
    Node *c = &c_;
}

void testFamilyInit() {

    Node a_;
    Node b_;
    Node c_;

    Node* a = &a_;
    Node* b = &b_;
    Node* c = &c_;

    /* -------------------------------------- */

    Family f_1(vector<Node*>{a,b,c},vector<Node*>({}));
    Family* f = &f_1;

    unordered_set<Node*> expected({a,b,c});
    NodeIterator parents = f->getParents();
    Node* current = parents.getCurrent();
    while(current) {

        if(expected.find(current) == expected.end()) {
            string message = "Coulnd't find this person!";
            failWithMessage(__FILE__,__LINE__,message);
        }
        expected.erase(current);
        current = parents.next();
    }
    if(expected.size() != 0) {
        string message = "This should be empty!";
        failWithMessage(__FILE__,__LINE__,message);
    }

    /* -------------------------------------- */

    Family f_2(vector<Node*>{a,b},vector<Node*>({c}));
    f = &f_2;

    expected = unordered_set<Node*>({a,b});
    parents = f->getParents();
    Node* current = parents.getCurrent();
    while(current) {
        if(expected.find(current) == expected.end()) {
            string message = "Coulnd't find this person!";
            failWithMessage(__FILE__,__LINE__,message);
        }
        expected.erase(current);
        current = parents.next();
    }
    if(expected.size() != 0) {
        string message = "This should be empty!";
        failWithMessage(__FILE__,__LINE__,message);
    }

    expected = unordered_set<Node*>({c});
    NodeIterator children = f->getChildren();
    Node* current = children.getCurrent();
    while(current) {
        if(expected.find(current) == expected.end()) {
            string message = "Coulnd't find this person!";
            failWithMessage(__FILE__,__LINE__,message);
        }
        expected.erase(current);
        current = children.next();
    }
    if(expected.size() != 0) {
        string message = "This should be empty!";
        failWithMessage(__FILE__,__LINE__,message);
    }
}

void test



