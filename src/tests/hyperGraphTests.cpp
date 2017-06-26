#include <iostream>
#include <unordered_set>
#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraph.h"
#include "/Users/Eddie/hyperGraphEM/src/tests/testMain.h"

void testNodeInit() {

    Node a_;
    Node b_;
    Node c_;
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
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);
    Node* n10 = new Node(10);
    Node* n11 = new Node(11);
    Node* n12 = new Node(12);
    Node* n13 = new Node(13);
    Node* n14 = new Node(14);
    Node* n15 = new Node(15);
    Node* n16 = new Node(16);
    Node* n17 = new Node(17);
    Node* n18 = new Node(18);
    Node* n19 = new Node(19);
    Node* n20 = new Node(20);
    Node* n21 = new Node(21);
    Node* n22 = new Node(22);
    Node* n23 = new Node(23);
    Node* n24 = new Node(24);
    Node* n25 = new Node(25);
    Node* n26 = new Node(26);
    Node* n27 = new Node(27);
    Node* n28 = new Node(28);
    Node* n29 = new Node(29);
    Node* n30 = new Node(30);
    Node* n31 = new Node(31);
    Node* n32 = new Node(32);
    Node* n33 = new Node(33);
    vector<Node*> nodes({n1,n2,n3,n4,n5,n6,n7,n8,n9,n10,n11,n12,n13,n14,n15,n16,n17,n18,n19,n20,n21,n22,n23,n24,n25,n26,n27,n28,n29,n30,n31,n32,n33});

    Family* f1 = new Family(vector<Node*>({n1,n2,n3}),vector<Node*>({n6,n7}));
    f1->id = 1;
    Family* f2 = new Family(vector<Node*>({n4,n5,n6}),vector<Node*>({n12,n17}));
    f2->id = 2;
    Family* f3 = new Family(vector<Node*>({n8,n9}),vector<Node*>({n11}));
    f3->id = 3;
    Family* f4 = new Family(vector<Node*>({n10,n11,n12}),vector<Node*>({n20,n21}));
    f4->id = 4;
    Family* f5 = new Family(vector<Node*>({n13,n14}),vector<Node*>({n16}));
    f5->id = 5;
    Family* f6 = new Family(vector<Node*>({n12,n15,n16}),vector<Node*>({n22,n23,n24}));
    f6->id = 6;
    Family* f7 = new Family(vector<Node*>({n17,n18,n19}),vector<Node*>({n32,n33}));
    f7->id = 7;
    Family* f8 = new Family(vector<Node*>({n24,n25}),vector<Node*>({n27}));
    f8->id = 8;
    Family* f9 = new Family(vector<Node*>({n26,n12}),vector<Node*>({n28,n29}));
    f9->id = 9;
    Family* f10 = new Family(vector<Node*>({n29,n30}),vector<Node*>({n31}));
    f10->id = 10;
    vector<Family*> families({f1,f2,f3,f4,f5,f6,f7,f8,f9,f10});

    return pair<vector<Node*>,vector<Family*>>(nodes,families);
}

void deleteDAHTest(pair<vector<Node*>,vector<Family*>> nodesAndFamilies) {

    vector<Node*> nodes = nodesAndFamilies.first;
    vector<Family*> families = nodesAndFamilies.second;

    for(Family* f:families) {
        delete f;
    }
    for(Node* n: nodes) {
        delete n;
    }
}

void compareResults(unordered_set<Node*> returned, unordered_set<Node*> expected) {

    for(Node* node: returned) {
        if(expected.find(node) == expected.end()) {
            failWithMessage(__FILE__,__LINE__,"This node should not be here! ("+to_string(node->id)+")");
        }
        expected.erase(node);
    }
    if(expected.size() > 0) {
        failWithMessage(__FILE__,__LINE__,"Didn't iterate over all of the nodes!");
    }
}

void compareResults(unordered_set<Family*> returned, unordered_set<Family*> expected) {

    for(Family* family: returned) {
        if(expected.find(family) == expected.end()) {
            failWithMessage(__FILE__,__LINE__,"This family should not be here! ("+to_string(family->id)+")");
        }
        expected.erase(family);
    }
    if(expected.size() > 0) {
        failWithMessage(__FILE__,__LINE__,"Didn't iterate over all of the families!");
    }
}

void compareResults(NodeIterator& returned, unordered_set<Node*> expected) {

    cout << "\n --------- \n " << endl;
    for(Node* node = returned.getCurrent(); node != nullptr; node = returned.next()) {
        if(expected.find(node) == expected.end()) {
            failWithMessage(__FILE__,__LINE__,"This node should not be here! ("+to_string(node->id)+")");
        }
        cout << "Found node: " << node->id << endl;
        expected.erase(node);
    }
    if(expected.size() > 0) {
        failWithMessage(__FILE__,__LINE__,"Didn't iterate over all of the families!");
    }
}

Node* getNode(const vector<Node*>& nodes, int number) {
    return nodes.at(number-1);
}

Family* getFamily(const vector<Family*>& families, int number) {
    return families.at(number-1);
}

void testGetParentsNode() {
    pair<vector<Node*>,vector<Family*>> dahPair = testDAH();
    vector<Node*> nodes = dahPair.first;
    DirectedAcyclicHypergraph dah(dahPair.second);

    unordered_set<Node*> expected;
    unordered_set<Node*> parents;

    /* ------------------------------------- */
    Node* n12 = getNode(nodes,12);
    parents = dah.getParents(n12);
    Node* n4 = getNode(nodes,4);
    Node* n5 = getNode(nodes,5);
    Node* n6 = getNode(nodes,6);
    expected = unordered_set<Node*>({n4,n5,n6});
    compareResults(parents, expected);
    /* ------------------------------------- */
    parents = dah.getParents(n12);
    expected = unordered_set<Node*>({n4,n5,n6});
    compareResults(parents, expected);
    /* ------------------------------------- */
    Node* n23 = getNode(nodes,23);
    Node* n15 = getNode(nodes,15);
    Node* n16 = getNode(nodes,16);
    parents = dah.getParents(n23);
    expected = unordered_set<Node*>({n12,n15,n16});
    compareResults(parents, expected);
    /* ------------------------------------- */
    Node* n1 = getNode(nodes,1);
    parents = dah.getParents(n1);
    expected = unordered_set<Node*>({});
    compareResults(parents, expected);
    /* ------------------------------------- */
    Node* n27 = getNode(nodes,27);
    Node* n24 = getNode(nodes,24);
    Node* n25 = getNode(nodes,25);
    parents = dah.getParents(n27);
    expected = unordered_set<Node*>({n24,n25});
    compareResults(parents, expected);


    deleteDAHTest(dahPair);
}

void testGetChildrenNode() {
    pair<vector<Node*>,vector<Family*>> dahPair = testDAH();
    vector<Node*> nodes = dahPair.first;
    DirectedAcyclicHypergraph dah(dahPair.second);

    unordered_set<Node*> expected;
    unordered_set<Node*> children;

    /* ------------------------------------- */
    Node* n12 = getNode(nodes,12);
    Node* n20 = getNode(nodes,20);
    Node* n21 = getNode(nodes,21);
    Node* n22 = getNode(nodes,22);
    Node* n23 = getNode(nodes,23);
    Node* n24 = getNode(nodes,24);
    Node* n28 = getNode(nodes,28);
    Node* n29 = getNode(nodes,29);
    children = dah.getChildren(n12);
    expected = unordered_set<Node*>({n20,n21,n22,n23,n24,n28,n29});
    compareResults(children, expected);
    /* ------------------------------------- */
    children = dah.getChildren(n12);
    expected = unordered_set<Node*>({n20,n21,n22,n23,n24,n28,n29});
    compareResults(children, expected);
    /* ------------------------------------- */
    Node* n1 = getNode(nodes,1);
    Node* n6 = getNode(nodes,6);
    Node* n7 = getNode(nodes,7);
    children = dah.getChildren(n1);
    expected = unordered_set<Node*>({n6,n7});
    compareResults(children, expected);
    /* ------------------------------------- */
    Node* n27 = getNode(nodes,27);
    children = dah.getChildren(n27);
    expected = unordered_set<Node*>({});
    compareResults(children, expected);


    deleteDAHTest(dahPair);
}

void testGetFamiliesNode() {
    pair<vector<Node*>,vector<Family*>> dahPair = testDAH();
    vector<Node*> nodes = dahPair.first;
    vector<Family*> families = dahPair.second;
    DirectedAcyclicHypergraph dah(families);

    unordered_set<Family*> expected;
    unordered_set<Family*> families_;

    /* ------------------------------------- */
    Node* n12 = getNode(nodes,12);
    Family* f2 = getFamily(families,2);
    Family* f4 = getFamily(families,4);
    Family* f6 = getFamily(families,6);
    Family* f9 = getFamily(families,9);
    families_ = dah.getFamilies(n12);
    expected = unordered_set<Family*>({f2,f4,f6,f9});
    compareResults(expected,families_);
    /* ------------------------------------- */
    families_ = dah.getFamilies(n12);
    expected = unordered_set<Family*>({f2,f4,f6,f9});
    compareResults(expected,families_);
    /* ------------------------------------- */
    Node* n13 = getNode(nodes,13);
    Family* f5 = getFamily(families,5);
    families_ = dah.getFamilies(n13);
    expected = unordered_set<Family*>({f5});
    compareResults(expected,families_);
    /* ------------------------------------- */
    Node* n27 = getNode(nodes,27);
    Family* f8 = getFamily(families,8);
    families_ = dah.getFamilies(n27);
    expected = unordered_set<Family*>({f8});
    compareResults(expected,families_);



    deleteDAHTest(dahPair);
}

void testGetFamiliesIfParentNode() {
   pair<vector<Node*>,vector<Family*>> dahPair = testDAH();
    vector<Node*> nodes = dahPair.first;
    vector<Family*> families = dahPair.second;
    DirectedAcyclicHypergraph dah(families);

    unordered_set<Family*> expected;
    unordered_set<Family*> families_;

    /* ------------------------------------- */
    Node* n12 = getNode(nodes,12);
    Family* f4 = getFamily(families,4);
    Family* f6 = getFamily(families,6);
    Family* f9 = getFamily(families,9);
    families_ = dah.getFamiliesIfParent(n12);
    expected = unordered_set<Family*>({f4,f6,f9});
    compareResults(expected,families_);
    /* ------------------------------------- */
    families_ = dah.getFamiliesIfParent(n12);
    expected = unordered_set<Family*>({f4,f6,f9});
    compareResults(expected,families_);
    /* ------------------------------------- */
    Node* n13 = getNode(nodes,13);
    Family* f5 = getFamily(families,5);
    families_ = dah.getFamiliesIfParent(n13);
    expected = unordered_set<Family*>({f5});
    compareResults(expected,families_);
    /* ------------------------------------- */
    Node* n27 = getNode(nodes,27);
    families_ = dah.getFamiliesIfParent(n27);
    expected = unordered_set<Family*>({});
    compareResults(expected,families_);



    deleteDAHTest(dahPair);
}

void testGetFamiliesIfChildNode() {
    pair<vector<Node*>,vector<Family*>> dahPair = testDAH();
    vector<Node*> nodes = dahPair.first;
    vector<Family*> families = dahPair.second;
    DirectedAcyclicHypergraph dah(families);

    unordered_set<Family*> expected;
    unordered_set<Family*> families_;

    /* ------------------------------------- */
    Node* n12 = getNode(nodes,12);
    Family* f2 = getFamily(families,2);
    families_ = dah.getFamiliesIfChild(n12);
    expected = unordered_set<Family*>({f2});
    compareResults(expected,families_);
    /* ------------------------------------- */
    families_ = dah.getFamiliesIfChild(n12);
    expected = unordered_set<Family*>({f2});
    compareResults(expected,families_);
    /* ------------------------------------- */
    Node* n13 = getNode(nodes,13);
    families_ = dah.getFamiliesIfChild(n13);
    expected = unordered_set<Family*>({});
    compareResults(expected,families_);
    /* ------------------------------------- */
    Node* n27 = getNode(nodes,27);
    Family* f8 = getFamily(families,8);
    families_ = dah.getFamiliesIfChild(n27);
    expected = unordered_set<Family*>({f8});
    compareResults(expected,families_);



    deleteDAHTest(dahPair);
}

void testGetNodesInFamilyFamily() {
    pair<vector<Node*>,vector<Family*>> dahPair = testDAH();
    vector<Node*> nodes = dahPair.first;
    vector<Family*> families = dahPair.second;
    DirectedAcyclicHypergraph dah(families);

    unordered_set<Node*> expected;
    unordered_set<Node*> nodes_;

    /* ------------------------------------- */
    Family* f6 = getFamily(families,6);
    Node* n12 = getNode(nodes,12);
    Node* n15 = getNode(nodes,15);
    Node* n16 = getNode(nodes,16);
    Node* n22 = getNode(nodes,22);
    Node* n23 = getNode(nodes,23);
    Node* n24 = getNode(nodes,24);
    nodes_ = dah.getNodesInFamily(f6);
    expected = unordered_set<Node*>({n12,n15,n16,n22,n23,n24});
    compareResults(expected,nodes_);
    /* ------------------------------------- */
    nodes_ = dah.getNodesInFamily(f6);
    expected = unordered_set<Node*>({n12,n15,n16,n22,n23,n24});
    compareResults(expected,nodes_);
    /* ------------------------------------- */
    Family* f2 = getFamily(families,2);
    Node* n4 = getNode(nodes,4);
    Node* n5 = getNode(nodes,5);
    Node* n6 = getNode(nodes,6);
    Node* n17 = getNode(nodes,17);
    nodes_ = dah.getNodesInFamily(f2);
    expected = unordered_set<Node*>({n12,n4,n5,n6,n17});
    compareResults(expected,nodes_);


    deleteDAHTest(dahPair);
}

void testGetParentsFamily() {
    pair<vector<Node*>,vector<Family*>> dahPair = testDAH();
    vector<Node*> nodes = dahPair.first;
    vector<Family*> families = dahPair.second;
    DirectedAcyclicHypergraph dah(families);

    unordered_set<Node*> expected;
    unordered_set<Node*> nodes_;

    /* ------------------------------------- */
    Family* f6 = getFamily(families,6);
    Node* n12 = getNode(nodes,12);
    Node* n15 = getNode(nodes,15);
    Node* n16 = getNode(nodes,16);
    nodes_ = dah.getParents(f6);
    expected = unordered_set<Node*>({n12,n15,n16});
    compareResults(expected,nodes_);
    /* ------------------------------------- */
    nodes_ = dah.getParents(f6);
    expected = unordered_set<Node*>({n12,n15,n16});
    compareResults(expected,nodes_);
    /* ------------------------------------- */
    Family* f2 = getFamily(families,2);
    Node* n4 = getNode(nodes,4);
    Node* n5 = getNode(nodes,5);
    Node* n6 = getNode(nodes,6);
    nodes_ = dah.getParents(f2);
    expected = unordered_set<Node*>({n4,n5,n6});
    compareResults(expected,nodes_);


    deleteDAHTest(dahPair);
}

void testGetChildrenFamily() {
    pair<vector<Node*>,vector<Family*>> dahPair = testDAH();
    vector<Node*> nodes = dahPair.first;
    vector<Family*> families = dahPair.second;
    DirectedAcyclicHypergraph dah(families);

    unordered_set<Node*> expected;
    unordered_set<Node*> nodes_;

    /* ------------------------------------- */
    Family* f6 = getFamily(families,6);
    Node* n22 = getNode(nodes,22);
    Node* n23 = getNode(nodes,23);
    Node* n24 = getNode(nodes,24);
    nodes_ = dah.getChildren(f6);
    expected = unordered_set<Node*>({n22,n23,n24});
    compareResults(expected,nodes_);
    /* ------------------------------------- */
    nodes_ = dah.getChildren(f6);
    expected = unordered_set<Node*>({n22,n23,n24});
    compareResults(expected,nodes_);
    /* ------------------------------------- */
    Family* f2 = getFamily(families,2);
    Node* n12 = getNode(nodes,12);
    Node* n17 = getNode(nodes,17);
    nodes_ = dah.getChildren(f2);
    expected = unordered_set<Node*>({n12,n17});
    compareResults(expected,nodes_);


    deleteDAHTest(dahPair);
}

void testGetAllFromFamilyExceptFromNode() {
    pair<vector<Node*>,vector<Family*>> dahPair = testDAH();
    vector<Node*> nodes = dahPair.first;
    vector<Family*> families = dahPair.second;
    DirectedAcyclicHypergraph dah(families);

    unordered_set<Node*> expected;
    NodeIterator result;
    /* ------------------------------------- */
    Family* f6 = getFamily(families,6);
    Node* n12 = getNode(nodes,12);
    Node* n13 = getNode(nodes,13);
    Node* n14 = getNode(nodes,14);
    Node* n15 = getNode(nodes,15);
    Node* n16 = getNode(nodes,16);
    Node* n22 = getNode(nodes,22);
    Node* n23 = getNode(nodes,23);
    Node* n24 = getNode(nodes,24);
    Node* n25 = getNode(nodes,25);
    Node* n27 = getNode(nodes,27);
    result = dah.getAllFromFamilyExceptFromNode(f6,n12);
    expected = unordered_set<Node*>({n13,n14,n15,n16,n22,n23,n24,n25,n27});
    compareResults(result,expected);
    /* ------------------------------------- */
    result = dah.getAllFromFamilyExceptFromNode(f6,n12);
    expected = unordered_set<Node*>({n13,n14,n15,n16,n22,n23,n24,n25,n27});
    compareResults(result,expected);
    /* ------------------------------------- */
    Family* f10 = getFamily(families,10);
    Node* n31 = getNode(nodes,31);
    result = dah.getAllFromFamilyExceptFromNode(f10,n31);
    expected.insert(nodes.begin(),nodes.end());
    expected.erase(n31);
    compareResults(result,expected);


    deleteDAHTest(dahPair);
}

void testGetNodesUpFrom() {
    pair<vector<Node*>,vector<Family*>> dahPair = testDAH();
    vector<Node*> nodes = dahPair.first;
    vector<Family*> families = dahPair.second;
    DirectedAcyclicHypergraph dah(families);

    unordered_set<Node*> expected;
    NodeIterator result;
    /* ------------------------------------- */
    Node* n12 = getNode(nodes,12);
    Node* n1 = getNode(nodes,1);
    Node* n2 = getNode(nodes,2);
    Node* n3 = getNode(nodes,3);
    Node* n4 = getNode(nodes,4);
    Node* n5 = getNode(nodes,5);
    Node* n6 = getNode(nodes,6);
    Node* n7 = getNode(nodes,7);
    Node* n17 = getNode(nodes,17);
    Node* n18 = getNode(nodes,18);
    Node* n19 = getNode(nodes,19);
    Node* n32 = getNode(nodes,32);
    Node* n33 = getNode(nodes,33);
    result = dah.getNodesUpFrom(n12);
    expected = unordered_set<Node*>({n1,n2,n3,n4,n5,n6,n7,n17,n18,n19,n32,n33});
    compareResults(result,expected);
    /* ------------------------------------- */
    result = dah.getNodesUpFrom(n12);
    expected = unordered_set<Node*>({n1,n2,n3,n4,n5,n6,n7,n17,n18,n19,n32,n33});
    compareResults(result,expected);
    /* ------------------------------------- */
    result = dah.getNodesUpFrom(n1);
    expected = unordered_set<Node*>({});
    compareResults(result,expected);
    /* ------------------------------------- */
    Node* n31 = getNode(nodes,31);
    result = dah.getNodesUpFrom(n31);
    expected.insert(nodes.begin(),nodes.end());
    expected.erase(n31);
    compareResults(result,expected);


    deleteDAHTest(dahPair);
}

void testGetNodesUpFromExceptFromFamily() {
    pair<vector<Node*>,vector<Family*>> dahPair = testDAH();
    vector<Node*> nodes = dahPair.first;
    vector<Family*> families = dahPair.second;
    DirectedAcyclicHypergraph dah(families);

    unordered_set<Node*> expected;
    NodeIterator result;
    /* ------------------------------------- */
    Node* n12 = getNode(nodes,12);
    Family* f2 = getFamily(families,2);
    result = dah.getNodesUpFromExceptFromFamily(n12,f2);
    expected = unordered_set<Node*>({});
    compareResults(result,expected);
    /* ------------------------------------- */
    result = dah.getNodesUpFromExceptFromFamily(n12,f2);
    expected = unordered_set<Node*>({});
    compareResults(result,expected);
    /* ------------------------------------- */
    Node* n1 = getNode(nodes,1);
    Family* f1 = getFamily(families,1);
    result = dah.getNodesUpFromExceptFromFamily(n1,f1);
    expected = unordered_set<Node*>({});
    compareResults(result,expected);


    deleteDAHTest(dahPair);
}

void testGetNodesDownFrom() {
    pair<vector<Node*>,vector<Family*>> dahPair = testDAH();
    vector<Node*> nodes = dahPair.first;
    vector<Family*> families = dahPair.second;
    DirectedAcyclicHypergraph dah(families);

    unordered_set<Node*> expected;
    NodeIterator result;
    /* ------------------------------------- */
    Node* n12 = getNode(nodes,12);
    Node* n8 = getNode(nodes,8);
    Node* n9 = getNode(nodes,9);
    Node* n10 = getNode(nodes,10);
    Node* n11 = getNode(nodes,11);
    Node* n13 = getNode(nodes,13);
    Node* n14 = getNode(nodes,14);
    Node* n15 = getNode(nodes,15);
    Node* n16 = getNode(nodes,16);
    Node* n20 = getNode(nodes,20);
    Node* n21 = getNode(nodes,21);
    Node* n22 = getNode(nodes,22);
    Node* n23 = getNode(nodes,23);
    Node* n24 = getNode(nodes,24);
    Node* n25 = getNode(nodes,25);
    Node* n26 = getNode(nodes,26);
    Node* n27 = getNode(nodes,27);
    Node* n28 = getNode(nodes,28);
    Node* n29 = getNode(nodes,29);
    Node* n30 = getNode(nodes,30);
    Node* n31 = getNode(nodes,31);
    result = dah.getNodesDownFrom(n12);
    expected = unordered_set<Node*>({n8,n9,n10,n11,n13,n14,n15,n16,n20,n21,n22,n23,n24,n25,n26,n27,n28,n29,n30,n31});
    compareResults(result,expected);
    /* ------------------------------------- */
    result = dah.getNodesDownFrom(n12);
    expected = unordered_set<Node*>({n8,n9,n10,n11,n13,n14,n15,n16,n20,n21,n22,n23,n24,n25,n26,n27,n28,n29,n30,n31});
    compareResults(result,expected);
    /* ------------------------------------- */
    Node* n1 = getNode(nodes,1);
    result = dah.getNodesDownFrom(n1);
    expected = unordered_set<Node*>({});
    expected.insert(nodes.begin(),nodes.end());
    expected.erase(n1);
    compareResults(result,expected);
    /* ------------------------------------- */
    result = dah.getNodesDownFrom(n31);
    expected = unordered_set<Node*>({});
    compareResults(result,expected);

    deleteDAHTest(dahPair);
}

void testGetNodesDownFromExceptFromFamily() {
    pair<vector<Node*>,vector<Family*>> dahPair = testDAH();
    vector<Node*> nodes = dahPair.first;
    vector<Family*> families = dahPair.second;
    DirectedAcyclicHypergraph dah(families);

    unordered_set<Node*> expected;
    NodeIterator result;
    /* ------------------------------------- */
    Node* n12 = getNode(nodes,12);
    Family* f4 = getFamily(families,4);
    Node* n13 = getNode(nodes,13);
    Node* n14 = getNode(nodes,14);
    Node* n15 = getNode(nodes,15);
    Node* n16 = getNode(nodes,16);
    Node* n22 = getNode(nodes,22);
    Node* n23 = getNode(nodes,23);
    Node* n24 = getNode(nodes,24);
    Node* n25 = getNode(nodes,25);
    Node* n26 = getNode(nodes,26);
    Node* n27 = getNode(nodes,27);
    Node* n28 = getNode(nodes,28);
    Node* n29 = getNode(nodes,29);
    Node* n30 = getNode(nodes,30);
    Node* n31 = getNode(nodes,31);
    result = dah.getNodesDownFromExceptFromFamily(n12,f4);
    expected = unordered_set<Node*>({n13,n14,n15,n16,n22,n23,n24,n25,n26,n27,n28,n29,n30,n31});
    compareResults(result,expected);
    /* ------------------------------------- */
    result = dah.getNodesDownFromExceptFromFamily(n12,f4);
    expected = unordered_set<Node*>({n13,n14,n15,n16,n22,n23,n24,n25,n26,n27,n28,n29,n30,n31});
    compareResults(result,expected);
    /* ------------------------------------- */
    Node* n1 = getNode(nodes,1);
    Family* f1 = getFamily(families,1);
    result = dah.getNodesDownFromExceptFromFamily(n1,f1);
    expected = unordered_set<Node*>({});
    compareResults(result,expected);

    deleteDAHTest(dahPair);
}


void allDAHTests() {
    testNodeInit();
    testFamilyInit();
    testGetParentsNode();
    testGetChildrenNode();
    testGetFamiliesNode();
    testGetFamiliesIfParentNode();
    testGetFamiliesIfChildNode();
    testGetNodesInFamilyFamily();
    testGetParentsFamily();
    testGetChildrenFamily();
    testGetAllFromFamilyExceptFromNode();
    testGetNodesUpFrom();
    testGetNodesUpFromExceptFromFamily();
    testGetNodesDownFrom();
    testGetNodesDownFromExceptFromFamily();
}


