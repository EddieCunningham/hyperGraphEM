#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraph.h"

void DirectedAcyclicHypergraph::_addFamily(Family* family) {
    _families.push_back(family);
}

unordered_set<Node*> DirectedAcyclicHypergraph::getAllNodes() const {

    unordered_set<Node*> ans;
    for(Family* family: _families) {
        vector<Node*> nodes = family->_getNodes();
        ans.insert(nodes.begin(),nodes.end());
    }
    return ans;
}

unordered_set<Family*> DirectedAcyclicHypergraph::getAllFamilies() const {

    unordered_set<Family*> ans;
    ans.insert(_families.begin(),_families.end());
    return ans;
}


unordered_set<Node*> DirectedAcyclicHypergraph::getParents(Node* node) const {

    vector<Family*> upFamilies = node->_getUpFamilies();

    unordered_set<Node*> ans;
    for(Family* family: upFamilies) {
        vector<Node*> parents = family->_getParents();
        ans.insert(parents.begin(),parents.end());
    }
    return ans;
}

unordered_set<Node*> DirectedAcyclicHypergraph::getChildren(Node* node) const {

    vector<Family*> downFamilies = node->_getDownFamilies();

    unordered_set<Node*> ans;
    for(Family* family: downFamilies) {
        vector<Node*> children = family->_getChildren();
        ans.insert(children.begin(),children.end());
    }
    return ans;
}

unordered_set<Family*> DirectedAcyclicHypergraph::getFamiliesIfParent(Node* node) const {
    
    vector<Family*> downFamilies = node->_getDownFamilies();
    unordered_set<Family*> ans;
    ans.insert(downFamilies.begin(),downFamilies.end());
    return ans;
}
unordered_set<Family*> DirectedAcyclicHypergraph::getFamiliesIfChild(Node* node) const {
    
    vector<Family*> upFamilies = node->_getUpFamilies();
    unordered_set<Family*> ans;
    ans.insert(upFamilies.begin(),upFamilies.end());
    return ans;
}

unordered_set<Family*> DirectedAcyclicHypergraph::getFamilies(Node* node) const {

    vector<Family*> downFamilies = node->_getDownFamilies();
    vector<Family*> upFamilies = node->_getUpFamilies();

    unordered_set<Family*> ans;
    ans.insert(downFamilies.begin(),downFamilies.end());
    ans.insert(upFamilies.begin(),upFamilies.end());

    return ans;
}


unordered_set<Node*> DirectedAcyclicHypergraph::getParents(Family* family) const {
    vector<Node*> parents = family->_getParents();
    unordered_set<Node*> ans;
    ans.insert(parents.begin(),parents.end());
    return ans;
}
unordered_set<Node*> DirectedAcyclicHypergraph::getChildren(Family* family) const {
    vector<Node*> children = family->_getChildren();
    unordered_set<Node*> ans;
    ans.insert(children.begin(),children.end());
    return ans;
}

unordered_set<Node*> DirectedAcyclicHypergraph::getNodesInFamily(Family* family) const {
    
    vector<Node*> parents = family->_getParents();
    vector<Node*> children = family->_getChildren();

    unordered_set<Node*> ans;
    ans.insert(parents.begin(),parents.end());
    ans.insert(children.begin(),children.end());

    return ans;
}

NodeIterator DirectedAcyclicHypergraph::getAllFromFamilyExceptFromNode(Family* family, Node* node) const {

    unordered_set<Node*> startNodes = getNodesInFamily(family);
    startNodes.erase(node);
    NodeIterator toReturn(startNodes,vector<Family*>({family}));

    return toReturn;
}

NodeIterator DirectedAcyclicHypergraph::getNodesUpFromExceptFromFamily(Node* node, Family* family) const {
    vector<Family*> startFamilies = vector<Family*>();
    unordered_set<Node*> startNodes = unordered_set<Node*>();

    vector<Family*> upFamilies = node->_getUpFamilies();
    for(Family* fam: upFamilies) {

        if(fam == family) {
            continue;
        }

        vector<Node*> nodes = fam->_getNodes();
        startNodes.insert(nodes.begin(),nodes.end());
        startFamilies.push_back(fam);
    }

    startNodes.erase(node);
    NodeIterator toReturn(startNodes,startFamilies);

    return toReturn;
}

NodeIterator DirectedAcyclicHypergraph::getNodesUpFrom(Node* node) const {
    NodeIterator toReturn = getNodesUpFromExceptFromFamily(node,nullptr);
    return toReturn;
}


NodeIterator DirectedAcyclicHypergraph::getNodesDownFromExceptFromFamily(Node* node, Family* family) const {
    vector<Family*> startFamilies = vector<Family*>();
    unordered_set<Node*> startNodes = unordered_set<Node*>();

    vector<Family*> downFamilies = node->_getDownFamilies();
    for(Family* fam: downFamilies) {

        if(fam == family) {
            continue;
        }

        vector<Node*> nodes = fam->_getNodes();
        startNodes.insert(nodes.begin(),nodes.end());
        startFamilies.push_back(fam);
    }

    startNodes.erase(node);
    NodeIterator toReturn(startNodes,startFamilies);

    return toReturn;
}

NodeIterator DirectedAcyclicHypergraph::getNodesDownFrom(Node* node) const {
    NodeIterator toReturn = getNodesDownFromExceptFromFamily(node,nullptr);
    return toReturn;
}

