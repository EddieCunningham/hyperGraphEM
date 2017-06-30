#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraph.h"

void DirectedAcyclicHypergraph::_addFamily(Family* family) {
    _families.insert(family);
}

NodeIterator DirectedAcyclicHypergraph::getAllNodesInIterator() const {

    unordered_set<Node*> nodes = getAllNodes();
    Node* startNode = *(nodes.begin());
    
    unordered_set<Node*> startNodes = unordered_set<Node*>({startNode});
    unordered_set<Family*> famsToBranchTo = startNode->getFamilies();
    unordered_set<Family*> famsToSkip = unordered_set<Family*>({});
    bool keepFirstNode = true;

    NodeIterator toReturn(startNodes,famsToBranchTo,famsToSkip,keepFirstNode);

    return toReturn;
}

unordered_set<Node*> DirectedAcyclicHypergraph::getAllNodes() const {

    unordered_set<Node*> ans;
    for(Family* family: _families) {
        unordered_set<Node*> nodes = family->_getNodes();
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

    unordered_set<Family*> upFamilies = node->_getUpFamilies();

    unordered_set<Node*> ans;
    for(Family* family: upFamilies) {
        unordered_set<Node*> parents = family->_getParents();
        ans.insert(parents.begin(),parents.end());
    }
    return ans;
}

unordered_set<Node*> DirectedAcyclicHypergraph::getChildren(Node* node) const {

    unordered_set<Family*> downFamilies = node->_getDownFamilies();

    unordered_set<Node*> ans;
    for(Family* family: downFamilies) {
        unordered_set<Node*> children = family->_getChildren();
        ans.insert(children.begin(),children.end());
    }
    return ans;
}

unordered_set<Family*> DirectedAcyclicHypergraph::getFamiliesIfParent(Node* node) const {
    
    unordered_set<Family*> downFamilies = node->_getDownFamilies();
    unordered_set<Family*> ans;
    ans.insert(downFamilies.begin(),downFamilies.end());
    return ans;
}
unordered_set<Family*> DirectedAcyclicHypergraph::getFamiliesIfChild(Node* node) const {
    
    unordered_set<Family*> upFamilies = node->_getUpFamilies();
    unordered_set<Family*> ans;
    ans.insert(upFamilies.begin(),upFamilies.end());
    return ans;
}

unordered_set<Family*> DirectedAcyclicHypergraph::getFamilies(Node* node) const {

    unordered_set<Family*> downFamilies = node->_getDownFamilies();
    unordered_set<Family*> upFamilies = node->_getUpFamilies();

    unordered_set<Family*> ans;
    ans.insert(downFamilies.begin(),downFamilies.end());
    ans.insert(upFamilies.begin(),upFamilies.end());

    return ans;
}


unordered_set<Node*> DirectedAcyclicHypergraph::getParents(Family* family) const {
    unordered_set<Node*> parents = family->_getParents();
    unordered_set<Node*> ans;
    ans.insert(parents.begin(),parents.end());
    return ans;
}
unordered_set<Node*> DirectedAcyclicHypergraph::getChildren(Family* family) const {
    unordered_set<Node*> children = family->_getChildren();
    unordered_set<Node*> ans;
    ans.insert(children.begin(),children.end());
    return ans;
}

unordered_set<Node*> DirectedAcyclicHypergraph::getNodesInFamily(Family* family) const {
    
    unordered_set<Node*> parents = family->_getParents();
    unordered_set<Node*> children = family->_getChildren();

    unordered_set<Node*> ans;
    ans.insert(parents.begin(),parents.end());
    ans.insert(children.begin(),children.end());

    return ans;
}

/* ------------------------------------------------------------------------------- */

NodeIterator DirectedAcyclicHypergraph::getAllFromFamilyExceptFromNode(Family* family, Node* node, bool keepFirstNode) const {

    unordered_set<Node*> startNodes = unordered_set<Node*>({node});
    unordered_set<Family*> famsToBranchTo = unordered_set<Family*>({family});
    unordered_set<Family*> famsToSkip = unordered_set<Family*>({});
    NodeIterator toReturn(startNodes,famsToBranchTo,famsToSkip,keepFirstNode);

    return toReturn;
}

NodeIterator DirectedAcyclicHypergraph::getAllNodesExceptFromFamily(Family* family, Node* node, bool keepFirstNode) const {

    unordered_set<Node*> startNodes = unordered_set<Node*>({node});
    unordered_set<Family*> famsToBranchTo = node->getFamilies();
    unordered_set<Family*> famsToSkip = unordered_set<Family*>({family});

    famsToBranchTo.erase(family);
    NodeIterator toReturn(startNodes,famsToBranchTo,famsToSkip,keepFirstNode);

    return toReturn;
}

/* ------------------------------------------------------------------------------- */

NodeIterator DirectedAcyclicHypergraph::getNodesUpFromExceptFromFamily(Node* node, Family* family, bool keepFirstNode) const {
    
    unordered_set<Node*> startNodes = unordered_set<Node*>({node});
    unordered_set<Family*> famsToBranchTo = node->getUpFamilies();
    unordered_set<Family*> famsToSkip = unordered_set<Family*>({family});

    famsToBranchTo.erase(family);
    NodeIterator toReturn(startNodes,famsToBranchTo,famsToSkip,keepFirstNode);

    return toReturn;
}   

NodeIterator DirectedAcyclicHypergraph::getNodesUpFrom(Node* node, bool keepFirstNode) const {
    
    unordered_set<Node*> startNodes = unordered_set<Node*>({node});
    unordered_set<Family*> famsToBranchTo = node->getUpFamilies();
    unordered_set<Family*> famsToSkip = unordered_set<Family*>({});

    NodeIterator toReturn(startNodes,famsToBranchTo,famsToSkip,keepFirstNode);

    return toReturn;
}

/* ------------------------------------------------------------------------------- */


NodeIterator DirectedAcyclicHypergraph::getNodesDownFromExceptFromFamily(Node* node, Family* family, bool keepFirstNode) const {

    unordered_set<Node*> startNodes = unordered_set<Node*>({node});
    unordered_set<Family*> famsToBranchTo = node->getDownFamilies();
    unordered_set<Family*> famsToSkip = unordered_set<Family*>({family});

    famsToBranchTo.erase(family);
    NodeIterator toReturn(startNodes,famsToBranchTo,famsToSkip,keepFirstNode);

    return toReturn;
}

NodeIterator DirectedAcyclicHypergraph::getNodesDownFrom(Node* node, bool keepFirstNode) const {
    unordered_set<Node*> startNodes = unordered_set<Node*>({node});
    unordered_set<Family*> famsToBranchTo = node->getDownFamilies();
    unordered_set<Family*> famsToSkip = unordered_set<Family*>({});

    NodeIterator toReturn(startNodes,famsToBranchTo,famsToSkip,keepFirstNode);

    return toReturn;
}

