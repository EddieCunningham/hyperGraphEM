#include <iostream>
#include <unordered_set>
#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraph.h"
#include "/Users/Eddie/hyperGraphEM/src/tests/testMain.h"
#include "/Users/Eddie/hyperGraphEM/src/pedigreeParse/pedigreeToPedigree.h"

void testNodeInit() {

    Node a_(-1,nullptr);
    Node b_(-1,nullptr);
    Node c_(-1,nullptr);
}

void testFamilyInit() {

    Node a_(-1,nullptr);
    Node b_(-1,nullptr);
    Node c_(-1,nullptr);

    Node* a = &a_;
    Node* b = &b_;
    Node* c = &c_;

    /* -------------------------------------- */

    Family f_1(1,unordered_set<Node*>{a,b,c},unordered_set<Node*>({}));
    Family f_2(2,unordered_set<Node*>{a,b},unordered_set<Node*>({c}));
}

pair<unordered_set<Node*>,unordered_set<Family*>> testDAH() {
    Node* n1 = new Node(1,nullptr);
    Node* n2 = new Node(2,nullptr);
    Node* n3 = new Node(3,nullptr);
    Node* n4 = new Node(4,nullptr);
    Node* n5 = new Node(5,nullptr);
    Node* n6 = new Node(6,nullptr);
    Node* n7 = new Node(7,nullptr);
    Node* n8 = new Node(8,nullptr);
    Node* n9 = new Node(9,nullptr);
    Node* n10 = new Node(10,nullptr);
    Node* n11 = new Node(11,nullptr);
    Node* n12 = new Node(12,nullptr);
    Node* n13 = new Node(13,nullptr);
    Node* n14 = new Node(14,nullptr);
    Node* n15 = new Node(15,nullptr);
    Node* n16 = new Node(16,nullptr);
    Node* n17 = new Node(17,nullptr);
    Node* n18 = new Node(18,nullptr);
    Node* n19 = new Node(19,nullptr);
    Node* n20 = new Node(20,nullptr);
    Node* n21 = new Node(21,nullptr);
    Node* n22 = new Node(22,nullptr);
    Node* n23 = new Node(23,nullptr);
    Node* n24 = new Node(24,nullptr);
    Node* n25 = new Node(25,nullptr);
    Node* n26 = new Node(26,nullptr);
    Node* n27 = new Node(27,nullptr);
    Node* n28 = new Node(28,nullptr);
    Node* n29 = new Node(29,nullptr);
    Node* n30 = new Node(30,nullptr);
    Node* n31 = new Node(31,nullptr);
    Node* n32 = new Node(32,nullptr);
    Node* n33 = new Node(33,nullptr);
    unordered_set<Node*> nodes({n1,n2,n3,n4,n5,n6,n7,n8,n9,n10,n11,n12,n13,n14,n15,n16,n17,n18,n19,n20,n21,n22,n23,n24,n25,n26,n27,n28,n29,n30,n31,n32,n33});

    Family* f1 = new Family(1,unordered_set<Node*>({n1,n2,n3}),unordered_set<Node*>({n6,n7}));
    f1->id = 1;
    Family* f2 = new Family(2,unordered_set<Node*>({n4,n5,n6}),unordered_set<Node*>({n12,n17}));
    f2->id = 2;
    Family* f3 = new Family(3,unordered_set<Node*>({n8,n9}),unordered_set<Node*>({n11}));
    f3->id = 3;
    Family* f4 = new Family(4,unordered_set<Node*>({n10,n11,n12}),unordered_set<Node*>({n20,n21}));
    f4->id = 4;
    Family* f5 = new Family(5,unordered_set<Node*>({n13,n14}),unordered_set<Node*>({n16}));
    f5->id = 5;
    Family* f6 = new Family(6,unordered_set<Node*>({n12,n15,n16}),unordered_set<Node*>({n22,n23,n24}));
    f6->id = 6;
    Family* f7 = new Family(7,unordered_set<Node*>({n17,n18,n19}),unordered_set<Node*>({n32,n33}));
    f7->id = 7;
    Family* f8 = new Family(8,unordered_set<Node*>({n24,n25}),unordered_set<Node*>({n27}));
    f8->id = 8;
    Family* f9 = new Family(9,unordered_set<Node*>({n26,n12}),unordered_set<Node*>({n28,n29}));
    f9->id = 9;
    Family* f10 = new Family(10,unordered_set<Node*>({n29,n30}),unordered_set<Node*>({n31}));
    f10->id = 10;
    unordered_set<Family*> families({f1,f2,f3,f4,f5,f6,f7,f8,f9,f10});

    return pair<unordered_set<Node*>,unordered_set<Family*>>(nodes,families);
}

void deleteDAHTest(pair<unordered_set<Node*>,unordered_set<Family*>> nodesAndFamilies) {

    unordered_set<Node*> nodes = nodesAndFamilies.first;
    unordered_set<Family*> families = nodesAndFamilies.second;

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

void compareResults(NodeIterator& returned, unordered_set<int> expected) {

    cout << "\n --------- \n " << endl;
    for(Node* node = returned.getCurrent(); node != nullptr; node = returned.next()) {
        int id = node->id;
        if(expected.find(id) == expected.end()) {
            failWithMessage(__FILE__,__LINE__,"This node should not be here! ("+to_string(id)+")");
        }
        cout << "Found node: " << id << endl;
        expected.erase(id);
    }
    if(expected.size() > 0) {
        failWithMessage(__FILE__,__LINE__,"Didn't iterate over all of the families!");
    }
}

Node* getNode(const unordered_set<Node*>& nodes, int number) {
    for(Node* node: nodes) {
        if(node->id == number) {
            return node;
        }
    }
    failWithMessage(__FILE__,__LINE__,"DIDNT FIND THE THING");
    return nullptr;
}

Family* getFamily(const unordered_set<Family*>& families, int number) {
    for(Family* family: families) {
        if(family->id == number) {
            return family;
        }
    }
    failWithMessage(__FILE__,__LINE__,"DIDNT FIND THE THING");
    return nullptr;
}

void testGetParentsNode() {
    pair<unordered_set<Node*>,unordered_set<Family*>> dahPair = testDAH();
    unordered_set<Node*> nodes = dahPair.first;
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
    pair<unordered_set<Node*>,unordered_set<Family*>> dahPair = testDAH();
    unordered_set<Node*> nodes = dahPair.first;
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
    pair<unordered_set<Node*>,unordered_set<Family*>> dahPair = testDAH();
    unordered_set<Node*> nodes = dahPair.first;
    unordered_set<Family*> families = dahPair.second;
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
   pair<unordered_set<Node*>,unordered_set<Family*>> dahPair = testDAH();
    unordered_set<Node*> nodes = dahPair.first;
    unordered_set<Family*> families = dahPair.second;
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
    pair<unordered_set<Node*>,unordered_set<Family*>> dahPair = testDAH();
    unordered_set<Node*> nodes = dahPair.first;
    unordered_set<Family*> families = dahPair.second;
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
    pair<unordered_set<Node*>,unordered_set<Family*>> dahPair = testDAH();
    unordered_set<Node*> nodes = dahPair.first;
    unordered_set<Family*> families = dahPair.second;
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
    pair<unordered_set<Node*>,unordered_set<Family*>> dahPair = testDAH();
    unordered_set<Node*> nodes = dahPair.first;
    unordered_set<Family*> families = dahPair.second;
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
    pair<unordered_set<Node*>,unordered_set<Family*>> dahPair = testDAH();
    unordered_set<Node*> nodes = dahPair.first;
    unordered_set<Family*> families = dahPair.second;
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
    pair<unordered_set<Node*>,unordered_set<Family*>> dahPair = testDAH();
    unordered_set<Node*> nodes = dahPair.first;
    unordered_set<Family*> families = dahPair.second;
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
    result = dah.getAllFromFamilyExceptFromNode(f6,n12,false);
    expected = unordered_set<Node*>({n13,n14,n15,n16,n22,n23,n24,n25,n27});
    compareResults(result,expected);
    /* ------------------------------------- */
    result = dah.getAllFromFamilyExceptFromNode(f6,n12,false);
    expected = unordered_set<Node*>({n13,n14,n15,n16,n22,n23,n24,n25,n27});
    compareResults(result,expected);
    /* ------------------------------------- */
    Family* f10 = getFamily(families,10);
    Node* n31 = getNode(nodes,31);
    result = dah.getAllFromFamilyExceptFromNode(f10,n31,false);
    expected.insert(nodes.begin(),nodes.end());
    expected.erase(n31);
    compareResults(result,expected);


    deleteDAHTest(dahPair);
}

void testGetNodesUpFrom() {
    pair<unordered_set<Node*>,unordered_set<Family*>> dahPair = testDAH();
    unordered_set<Node*> nodes = dahPair.first;
    unordered_set<Family*> families = dahPair.second;
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
    result = dah.getNodesUpFrom(n12,false);
    expected = unordered_set<Node*>({n1,n2,n3,n4,n5,n6,n7,n17,n18,n19,n32,n33});
    compareResults(result,expected);
    /* ------------------------------------- */
    result = dah.getNodesUpFrom(n12,false);
    expected = unordered_set<Node*>({n1,n2,n3,n4,n5,n6,n7,n17,n18,n19,n32,n33});
    compareResults(result,expected);
    /* ------------------------------------- */
    result = dah.getNodesUpFrom(n1,false);
    expected = unordered_set<Node*>({});
    compareResults(result,expected);
    /* ------------------------------------- */
    Node* n31 = getNode(nodes,31);
    result = dah.getNodesUpFrom(n31,false);
    expected.insert(nodes.begin(),nodes.end());
    expected.erase(n31);
    compareResults(result,expected);


    deleteDAHTest(dahPair);
}

void testGetNodesUpFromExceptFromFamily() {
    pair<unordered_set<Node*>,unordered_set<Family*>> dahPair = testDAH();
    unordered_set<Node*> nodes = dahPair.first;
    unordered_set<Family*> families = dahPair.second;
    DirectedAcyclicHypergraph dah(families);

    unordered_set<Node*> expected;
    NodeIterator result;
    /* ------------------------------------- */
    Node* n12 = getNode(nodes,12);
    Family* f2 = getFamily(families,2);
    result = dah.getNodesUpFromExceptFromFamily(n12,f2,false);
    expected = unordered_set<Node*>({});
    compareResults(result,expected);
    /* ------------------------------------- */
    result = dah.getNodesUpFromExceptFromFamily(n12,f2,false);
    expected = unordered_set<Node*>({});
    compareResults(result,expected);
    /* ------------------------------------- */
    Node* n1 = getNode(nodes,1);
    Family* f1 = getFamily(families,1);
    result = dah.getNodesUpFromExceptFromFamily(n1,f1,false);
    expected = unordered_set<Node*>({});
    compareResults(result,expected);


    deleteDAHTest(dahPair);
}

void testGetNodesDownFrom() {
    pair<unordered_set<Node*>,unordered_set<Family*>> dahPair = testDAH();
    unordered_set<Node*> nodes = dahPair.first;
    unordered_set<Family*> families = dahPair.second;
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
    result = dah.getNodesDownFrom(n12,false);
    expected = unordered_set<Node*>({n8,n9,n10,n11,n13,n14,n15,n16,n20,n21,n22,n23,n24,n25,n26,n27,n28,n29,n30,n31});
    compareResults(result,expected);
    /* ------------------------------------- */
    result = dah.getNodesDownFrom(n12,false);
    expected = unordered_set<Node*>({n8,n9,n10,n11,n13,n14,n15,n16,n20,n21,n22,n23,n24,n25,n26,n27,n28,n29,n30,n31});
    compareResults(result,expected);
    /* ------------------------------------- */
    Node* n1 = getNode(nodes,1);
    result = dah.getNodesDownFrom(n1,false);
    expected = unordered_set<Node*>({});
    expected.insert(nodes.begin(),nodes.end());
    expected.erase(n1);
    compareResults(result,expected);
    /* ------------------------------------- */
    result = dah.getNodesDownFrom(n31,false);
    expected = unordered_set<Node*>({});
    compareResults(result,expected);

    deleteDAHTest(dahPair);
}

void testGetNodesDownFromExceptFromFamily() {
    pair<unordered_set<Node*>,unordered_set<Family*>> dahPair = testDAH();
    unordered_set<Node*> nodes = dahPair.first;
    unordered_set<Family*> families = dahPair.second;
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
    result = dah.getNodesDownFromExceptFromFamily(n12,f4,false);
    expected = unordered_set<Node*>({n13,n14,n15,n16,n22,n23,n24,n25,n26,n27,n28,n29,n30,n31});
    compareResults(result,expected);
    /* ------------------------------------- */
    result = dah.getNodesDownFromExceptFromFamily(n12,f4,false);
    expected = unordered_set<Node*>({n13,n14,n15,n16,n22,n23,n24,n25,n26,n27,n28,n29,n30,n31});
    compareResults(result,expected);
    /* ------------------------------------- */
    Node* n1 = getNode(nodes,1);
    Family* f1 = getFamily(families,1);
    result = dah.getNodesDownFromExceptFromFamily(n1,f1,false);
    expected = unordered_set<Node*>({});
    compareResults(result,expected);

    deleteDAHTest(dahPair);
}

/* ------------------------------------------------------------------------------------------------------- */


void testGetAllFromFamilyExceptFromNodeWithCycle() {

    PedigreeToPedigree pedigree("/Users/Eddie/kec-bot/app/pedigreeDataOLDBUTWORKS/test_cycle.json");
    Pedigree* dah = pedigree.getDAH();

    unordered_set<int> expected;
    NodeIterator result;
    /* ------------------------------------- */

    Node* n1 = pedigree.getPerson(1);
    Family* fam = *(n1->getDownFamilies().begin());
    result = dah->getAllFromFamilyExceptFromNode(fam,n1,false);
    expected = unordered_set<int>({2,3,4,5,6,7,8,9});
    compareResults(result,expected);

    /* ------------------------------------- */

    Node* n3 = pedigree.getPerson(3);
    fam = *(n3->getDownFamilies().begin());
    result = dah->getAllFromFamilyExceptFromNode(fam,n3,false);
    expected = unordered_set<int>({1,2,4,5,6,7,8,9});
    compareResults(result,expected);

    /* ------------------------------------- */

    Node* n;
    for(int i=1; i<10; ++i) {
        n = pedigree.getPerson(i);
        fam = *(n->getFamilies().begin());
        result = dah->getAllFromFamilyExceptFromNode(fam,n,false);
        expected = unordered_set<int>({1,2,3,4,5,6,7,8,9});
        expected.erase(i);
        compareResults(result,expected);
    }
}

void testGetNodesUpFromWithCycle() {
    PedigreeToPedigree pedigree("/Users/Eddie/kec-bot/app/pedigreeDataOLDBUTWORKS/test_cycle.json");
    Pedigree* dah = pedigree.getDAH();

    unordered_set<int> expected;
    NodeIterator result;
    /* ------------------------------------- */


    Node* n6 = pedigree.getPerson(6);
    result = dah->getNodesUpFrom(n6,false);
    expected = unordered_set<int>({1,2,3,4,5,7,8,9});
    compareResults(result,expected);

    /* ------------------------------------- */


    Node* n8 = pedigree.getPerson(8);
    result = dah->getNodesUpFrom(n8,false);
    expected = unordered_set<int>({1,2,3,4,5,7,6,9});
    compareResults(result,expected);
}

void testGetNodesUpFromExceptFromFamilyWithCycle() {
    PedigreeToPedigree pedigree("/Users/Eddie/kec-bot/app/pedigreeDataOLDBUTWORKS/test_cycle.json");
    Pedigree* dah = pedigree.getDAH();

    unordered_set<int> expected;
    NodeIterator result;
    /* ------------------------------------- */


    Node* n6 = pedigree.getPerson(6);
    Family* fam = *(n6->getDownFamilies().begin());
    result = dah->getNodesUpFromExceptFromFamily(n6,fam,false);
    expected = unordered_set<int>({1,2,3,4,5,7});
    compareResults(result,expected);

    /* ------------------------------------- */


    Node* n8 = pedigree.getPerson(8);
    fam = *(n8->getDownFamilies().begin());
    result = dah->getNodesUpFromExceptFromFamily(n8,fam,false);
    expected = unordered_set<int>({1,2,3,4,5,7});
    compareResults(result,expected);



}

void testGetNodesDownFromWithCycle() {
    PedigreeToPedigree pedigree("/Users/Eddie/kec-bot/app/pedigreeDataOLDBUTWORKS/test_cycle.json");
    Pedigree* dah = pedigree.getDAH();

    unordered_set<int> expected;
    NodeIterator result;
    /* ------------------------------------- */


    Node* n3 = pedigree.getPerson(3);
    result = dah->getNodesDownFrom(n3,false);
    expected = unordered_set<int>({1,2,4,5,6,7,8,9});
    compareResults(result,expected);

    /* ------------------------------------- */


    Node* n4 = pedigree.getPerson(4);
    result = dah->getNodesDownFrom(n4,false);
    expected = unordered_set<int>({1,2,3,5,6,7,8,9});
    compareResults(result,expected);



}

void testGetNodesDownFromExceptFromFamilyWithCycle() {
    PedigreeToPedigree pedigree("/Users/Eddie/kec-bot/app/pedigreeDataOLDBUTWORKS/test_cycle.json");
    Pedigree* dah = pedigree.getDAH();

    unordered_set<int> expected;
    NodeIterator result;
    /* ------------------------------------- */

    Node* n6 = pedigree.getPerson(6);
    Family* fam = *(n6->getDownFamilies().begin());
    result = dah->getNodesDownFromExceptFromFamily(n6,fam,false);
    expected = unordered_set<int>({});
    compareResults(result,expected);
    
    /* ------------------------------------- */
    
    fam = *(n6->getUpFamilies().begin());
    result = dah->getNodesDownFromExceptFromFamily(n6,fam,false);
    expected = unordered_set<int>({1,2,4,7,8,9});
    compareResults(result,expected);

    /* ------------------------------------- */

}


void nodeIteratorHashingTest() {
    PedigreeToPedigree pedigree("/Users/Eddie/kec-bot/app/pedigreeDataOLDBUTWORKS/test_cycle.json");
    Pedigree* dah = pedigree.getDAH();

    unordered_set<int> expected;
    NodeIterator result;
    unordered_set<int> andBack;
    /* ------------------------------------- */

    Node* n6 = pedigree.getPerson(6);
    Family* fam = *(n6->getDownFamilies().begin());
    result = dah->getNodesDownFromExceptFromFamily(n6,fam,false);
    string hash = result.getHash();

    // andBack = NodeIterator::setFromHash(hash);
    expected = unordered_set<int>({});

    // if(andBack != expected) {
    //     failWithMessage(__FILE__,__LINE__,"sets didnt match");
    // }
    
    /* ------------------------------------- */
    
    fam = *(n6->getUpFamilies().begin());
    result = dah->getNodesDownFromExceptFromFamily(n6,fam,false);
    hash = result.getHash();

    // andBack = NodeIterator::setFromHash(hash);
    expected = unordered_set<int>({1,2,4,7,8,9});
    // if(andBack != expected) {
    //     failWithMessage(__FILE__,__LINE__,"sets didnt match");
    // }

    /* ------------------------------------- */
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

    testGetAllFromFamilyExceptFromNodeWithCycle();
    testGetNodesUpFromWithCycle();
    testGetNodesUpFromExceptFromFamilyWithCycle();
    testGetNodesDownFromWithCycle();
    testGetNodesDownFromExceptFromFamilyWithCycle();


    nodeIteratorHashingTest();
}


