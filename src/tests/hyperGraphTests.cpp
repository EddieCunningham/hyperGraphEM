#include <iostream>
#include <unordered_set>
#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraph.h"

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
    Family f_2(vector<Node*>{a,b},vector<Node*>({c}));
}

pair<vector<Node*>,vector<Family*>> testDAH() {
    Node* n1 = new Node();
    Node* n2 = new Node();
    Node* n3 = new Node();
    Node* n4 = new Node();
    Node* n5 = new Node();
    Node* n6 = new Node();
    Node* n7 = new Node();
    Node* n8 = new Node();
    Node* n9 = new Node();
    Node* n10 = new Node();
    Node* n11 = new Node();
    Node* n12 = new Node();
    Node* n13 = new Node();
    Node* n14 = new Node();
    Node* n15 = new Node();
    Node* n16 = new Node();
    Node* n17 = new Node();
    Node* n18 = new Node();
    Node* n19 = new Node();
    Node* n20 = new Node();
    Node* n21 = new Node();
    Node* n22 = new Node();
    Node* n23 = new Node();
    Node* n24 = new Node();
    Node* n25 = new Node();
    Node* n26 = new Node();
    Node* n27 = new Node();
    Node* n28 = new Node();
    Node* n29 = new Node();
    Node* n30 = new Node();
    Node* n31 = new Node();
    Node* n32 = new Node();
    Node* n33 = new Node();
    vector<Node*> nodes({n1,n2,n3,n4,n5,n6,n7,n8,n9,n10,n11,n12,n13,n14,n15,n16,n17,n18,n19,n20,n21,n22,n23,n24,n25,n26,n27,n28,n29,n30,n31,n32,n33});

    Family* f1 = new Family(vector<Node*>({n1,n2,n3}),vector<Node*>({n6,n7}));
    Family* f2 = new Family(vector<Node*>({n4,n5,n6}),vector<Node*>({n12,n17}));
    Family* f3 = new Family(vector<Node*>({n8,n9}),vector<Node*>({n11}));
    Family* f4 = new Family(vector<Node*>({n10,n11,n12}),vector<Node*>({n20,n21}));
    Family* f5 = new Family(vector<Node*>({n13,n14}),vector<Node*>({n16}));
    Family* f6 = new Family(vector<Node*>({n12,n15,n16}),vector<Node*>({n22,n23,n24}));
    Family* f7 = new Family(vector<Node*>({n17,n18,n19}),vector<Node*>({n32,n33}));
    Family* f8 = new Family(vector<Node*>({n24,n25}),vector<Node*>({n27}));
    Family* f9 = new Family(vector<Node*>({n26,n12}),vector<Node*>({n28,n29}));
    Family* f10 = new Family(vector<Node*>({n29,n30}),vector<Node*>({n31}));
    vector<Family*> families({f1,f2,f3,f4,f5,f6,f7,f8,f9,f10});

    return pair<vector<Node*>,vector<Family*>>(nodes,families);
}

void deleteDAHTest(pair<vector<Node*>,vector<Family*>> nodesAndFamilies) {

    vector<Node*> nodes = nodesAndFamilies.first;
    vector<Family*> families = nodesAndFamilies.second;

    for(Family* f:families) {
        (*f).~();
        delete f;
    }
    for(Node* n: nodes) {
        delete n;
    }
}

void compareResults(NodeIterator& iterator, unordered_set<Node*> expected) {

    for(Node* node=NodeIterator.getCurrent(); node!=nullptr; node=iterator.next()) {
        if(expected.find(node) == expected.end()) {
            failWithMessage(__FILE__,__LINE__,"This node should not be here!");
        }
        expected.erase(node);
    }
    if(expected.size() > 0) {
        failWithMessage(__FILE__,__LINE__,"Didn't iterate over all of the nodes!");
    }
}

void compareResults(vector<Family*> returned, vector<Family*> expected) {

    for(Family* family: returned) {
        if(find(expected.begin(),expected.end(),family) == expected.end()) {
            failWithMessage(__FILE__,__LINE__,"This family should not be here!");
        }
        expected.erase(family);
    }
    if(expected.size() > 0) {
        failWithMessage(__FILE__,__LINE__,"Didn't iterate over all of the families!");
    }
}

Node* getNode(const vector<Node*>& nodes, int number) {
    return nodes.at(number-1);
}

void testGetParentsNode() {
    pair<vector<Node*>,vector<Family*>> dahPair = testDAH();
    vector<Node*> nodes = dahPair.first;
    DirectedAcyclicHypergraph dah(dahPair.second);

    unordered_set<Node*> expected;
    NodeIterator parents;

    /* ------------------------------------- */
    Node* n12 = getNode(12);
    parents = getParents(n12);
    Node* n4 = getNode(4);
    Node* n5 = getNode(5);
    Node* n6 = getNode(6);
    expected = unordered_set<Node*>({n4,n5,n6});
    compareResults(parents, expected);
    /* ------------------------------------- */
    parents = getParents(n12);
    expected = unordered_set<Node*>({n4,n5,n6});
    compareResults(parents, expected);
    /* ------------------------------------- */
    Node* n23 = getNode(23);
    Node* n15 = getNode(15);
    Node* n16 = getNode(16);
    parents = getParents(n23);
    expected = unordered_set<Node*>({n12,n15,n16});
    compareResults(parents, expected);
    /* ------------------------------------- */
    Node* n1 = getNode(1);
    parents = getParents(n1);
    expected = unordered_set<Node*>({});
    compareResults(parents, expected);
    /* ------------------------------------- */
    Node* n27 = getNode(27);
    Node* n24 = getNode(24);
    Node* n25 = getNode(25);
    parents = getParents(n27);
    expected = unordered_set<Node*>({n24,n25});
    compareResults(parents, expected);


    deleteDAHTest(dahPair);
}

void testGetChildrenNode() {
    pair<vector<Node*>,vector<Family*>> dahPair = testDAH();
    vector<Node*> nodes = dahPair.first;
    DirectedAcyclicHypergraph dah(dahPair.second);

    unordered_set<Node*> expected;
    NodeIterator children;

    /* ------------------------------------- */
    Node* n12 = getNode(12);
    Node* n20 = getNode(20);
    Node* n21 = getNode(21);
    Node* n22 = getNode(22);
    Node* n23 = getNode(23);
    Node* n24 = getNode(24);
    children = getChildren(n12);
    expected = unordered_set<Node*>({n20,n21,n22,n23,n24});
    compareResults(children, expected);
    /* ------------------------------------- */
    children = getChildren(n12);
    expected = unordered_set<Node*>({n20,n21,n22,n23,n24});
    compareResults(children, expected);
    /* ------------------------------------- */
    Node* n1 = getNode(1);
    Node* n6 = getNode(6);
    Node* n7 = getNode(7);
    children = getChildren(n1);
    expected = unordered_set<Node*>({n6,n7});
    compareResults(children, expected);
    /* ------------------------------------- */
    Node* n27 = getNode(27);
    Node* n24 = getNode(24);
    Node* n25 = getNode(25);
    children = getChildren(n27);
    expected = unordered_set<Node*>({});
    compareResults(children, expected);


    deleteDAHTest(dahPair);
}

void testGetFamiliesNode() {
    pair<vector<Node*>,vector<Family*>> dahPair = testDAH();
    vector<Node*> nodes = dahPair.first;
    DirectedAcyclicHypergraph dah(dahPair.second);

    unordered_set<Node*> expected;
    vector<Family*> families;

    /* ------------------------------------- */


    

    // families = getFamilies(Node* node);


    deleteDAHTest(dahPair);
}

void testGetFamiliesIfParentNode() {
    pair<vector<Node*>,vector<Family*>> dahPair = testDAH();
    vector<Node*> nodes = dahPair.first;
    DirectedAcyclicHypergraph dah(dahPair.second);

    unordered_set<Node*> expected;

    /* ------------------------------------- */


    // vector<Family*> getFamiliesIfParent(Node* node);


    deleteDAHTest(dahPair);
}

void testGetFamiliesIfChildNode() {
    pair<vector<Node*>,vector<Family*>> dahPair = testDAH();
    vector<Node*> nodes = dahPair.first;
    DirectedAcyclicHypergraph dah(dahPair.second);

    unordered_set<Node*> expected;

    /* ------------------------------------- */


    // vector<Family*> getFamiliesIfChild(Node* node);


    deleteDAHTest(dahPair);
}

void testGetNodesInFamilyFamily() {
    pair<vector<Node*>,vector<Family*>> dahPair = testDAH();
    vector<Node*> nodes = dahPair.first;
    DirectedAcyclicHypergraph dah(dahPair.second);

    unordered_set<Node*> expected;

    /* ------------------------------------- */


    // NodeIterator getNodesInFamily(Family* family);


    deleteDAHTest(dahPair);
}

void testGetParentsFamily() {
    pair<vector<Node*>,vector<Family*>> dahPair = testDAH();
    vector<Node*> nodes = dahPair.first;
    DirectedAcyclicHypergraph dah(dahPair.second);

    unordered_set<Node*> expected;

    /* ------------------------------------- */


    // NodeIterator getParents(Family* family);


    deleteDAHTest(dahPair);
}

void testGetChildrenFamily() {
    pair<vector<Node*>,vector<Family*>> dahPair = testDAH();
    vector<Node*> nodes = dahPair.first;
    DirectedAcyclicHypergraph dah(dahPair.second);

    unordered_set<Node*> expected;

    /* ------------------------------------- */


    // NodeIterator getChildren(Family* family);


    deleteDAHTest(dahPair);
}

void testGetAllFromFamilyExceptFromNode() {
    pair<vector<Node*>,vector<Family*>> dahPair = testDAH();
    vector<Node*> nodes = dahPair.first;
    DirectedAcyclicHypergraph dah(dahPair.second);

    unordered_set<Node*> expected;

    /* ------------------------------------- */


    // NodeIterator getAllFromFamilyExceptFromNode(Family* family, Node* node);


    deleteDAHTest(dahPair);
}

void testGetNodesUpFrom() {
    pair<vector<Node*>,vector<Family*>> dahPair = testDAH();
    vector<Node*> nodes = dahPair.first;
    DirectedAcyclicHypergraph dah(dahPair.second);

    unordered_set<Node*> expected;

    /* ------------------------------------- */


    // NodeIterator getNodesUpFrom(Node* node);


    deleteDAHTest(dahPair);
}

void testGetNodesUpFromExceptFromFamily() {
    pair<vector<Node*>,vector<Family*>> dahPair = testDAH();
    vector<Node*> nodes = dahPair.first;
    DirectedAcyclicHypergraph dah(dahPair.second);

    unordered_set<Node*> expected;

    /* ------------------------------------- */


    // NodeIterator getNodesUpFromExceptFromFamily(Node* node, Family* family);


    deleteDAHTest(dahPair);
}

void testGetNodesDownFrom() {
    pair<vector<Node*>,vector<Family*>> dahPair = testDAH();
    vector<Node*> nodes = dahPair.first;
    DirectedAcyclicHypergraph dah(dahPair.second);

    unordered_set<Node*> expected;

    /* ------------------------------------- */


    // NodeIterator getNodesDownFrom(Node* node);


    deleteDAHTest(dahPair);
}

void testGetNodesDownFromExceptFromFamily() {
    pair<vector<Node*>,vector<Family*>> dahPair = testDAH();
    vector<Node*> nodes = dahPair.first;
    DirectedAcyclicHypergraph dah(dahPair.second);

    unordered_set<Node*> expected;

    /* ------------------------------------- */


    // NodeIterator getNodesDownFromExceptFromFamily(Node* node, Family* family);


    deleteDAHTest(dahPair);
}


void allDAHTests() {
    testNodeInit();
    testFamilyInit();
    testGetParentsNode();
    testGetChildrenNode();
    // testGetFamiliesNode();
    // testGetFamiliesIfParentNode();
    // testGetFamiliesIfChildNode();
    // testGetNodesInFamilyFamily();
    // testGetParentsFamily();
    // testGetChildrenFamily();
    // testGetAllFromFamilyExceptFromNode();
    // testGetNodesUpFrom();
    // testGetNodesUpFromExceptFromFamily();
    // testGetNodesDownFrom();
    // testGetNodesDownFromExceptFromFamily();
}


