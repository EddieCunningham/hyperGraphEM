#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/forwardsBackwards.h"



bool nodeComp(const pair<Node*,unsigned>& a, const pair<Node*,unsigned>& b) {
    return a.first->id < b.first->id;
}

string FowrardsBackwards::_nodeMapHash(const unordered_map<Node*,unsigned>& nodeMap) {

    vector<pair<Node*,unsigned>> nodesAndIndex(nodeMap.begin(), nodeMap.end());
    sort(nodesAndIndex.begin(), nodesAndIndex.end(), nodeComp);
    
    string hash = "{";
    for(unsigned i=0; i<nodesAndIndex.size(); ++i) {
        unsigned id = nodesAndIndex.at(i).first->id;
        unsigned index = nodesAndIndex.at(i).second;
        hash += "{";
        hash += to_string(id);
        hash += ",";
        hash += to_string(index);
        hash += "}";
        if(i < nodesAndIndex.size()-1) {
            hash += ",";
        }
    }
    hash += "}";
    return hash;
}

string FowrardsBackwards::_iteratorAndConditionHash(const NodeIterator& iterator, const unordered_map<Node*,unsigned>& andedNodes, const unordered_map<Node*,unsigned>& conditionedNodes) {

    string hash1 = iterator.getHash();
    string hash2 = _nodeMapHash(andedNodes);
    string hash3 = _nodeMapHash(conditionedNodes);
    string ans = "["+hash1+","+hash2+","+hash3+"]";
    return ans;
}

void FowrardsBackwards::_storeSubProblemAns(const LogVar& ans, const NodeIterator& iterator, const unordered_map<Node*,unsigned>& andedNodes, const unordered_map<Node*,unsigned>& conditionedNodes) {

    string hash = _iteratorAndConditionHash(iterator,andedNodes,conditionedNodes);
    _storedAnswers[hash] = ans;
}

LogVar FowrardsBackwards::_getSubProblemAns(bool& found, const NodeIterator& iterator, const unordered_map<Node*,unsigned>& andedNodes, const unordered_map<Node*,unsigned>& conditionedNodes) {
    
    LogVar ans;
    string hash = _iteratorAndConditionHash(iterator,andedNodes,conditionedNodes);
    if(_storedAnswers.find(hash) != _storedAnswers.end()) {
        ans = _storedAnswers.at(hash);
        found = true;
    }
    else {
        found = false;
    }
    return ans;
}

LogVar FowrardsBackwards::_rootBaseCase(Node* nodeY, const unordered_map<Node*,unsigned>& andedNodes, const unordered_map<Node*,unsigned>& conditionedNodes) {
    LogVar ans;

    return ans;
}

LogVar FowrardsBackwards::_leafBaseCase(const unordered_map<Node*,unsigned>& andedNodes, const unordered_map<Node*,unsigned>& conditionedNodes) {
    LogVar ans;

    return ans;
}

LogVar FowrardsBackwards::_calcProb(NodeIterator yNodes, const unordered_map<Node*,unsigned>& andedNodes, const unordered_map<Node*,unsigned>& conditionedNodes) {
    LogVar ans;

    // branch over mates, parents, siblings, children
    // use node iterator to figure out if there is a cycle
    // this means implementing an == operator in node iterator

    // is there a way to know what to calculate based only on 
    // whats in anded nodes and in conditioned nodes?


    // anded -> sum over parents
    // conditioned -> sum over node corresponding to node iterator


    // seems like for a node in the anded nodes AND yNodes, knowing which families are in the yNodes
    // can help determine how to make calculations

    // for a set of nodes in conditioned nodes with any children in yNodes, can split that sub problem up

    // for a node with in conditioned nodes with children in yNodes, can split dat bitch up

    // need function to tell if node in anded nodes is in yNodes and return which families are in yNodes

    // need a function to tell if a set of parents in conditioned nodes have ALL children in yNodes


    // intersection of andedNodes and yNodes
    // intersection of conditionedNodes and yNodes
    // intersection of (andedNodes and conditionedNodes) and yNodes

    uComponent;
    alphaComponent;
    betaComponent;
    gammaComponent;


    return ans;
}

LogVar FowrardsBackwards::_getValue(NodeIterator yNodes, const unordered_map<Node*,unsigned>& andedNodes, const unordered_map<Node*,unsigned>& conditionedNodes) {

    LogVar val;
    bool valWasFound;
    val = _getSubProblemAns(valWasFound,yNodes,andedNodes,conditionedNodes);
    if(valWasFound) {
        return val;
    }

    val = _calcProb(yNodes,andedNodes,conditionedNodes);
    _storeSubProblemAns(val,yNodes,andedNodes,conditionedNodes);
    return val;
}

LogVar FowrardsBackwards::getAValFor(Node* node, unsigned x) {

    // using equation: u_n(x) * prod_{e in e(n^)}[ sum_{X in (^(e)\n)_x}[ \gamma_{n,e}(x,X)]]

    unordered_map<Node*,unsigned> n_x = unordered_map<Node*,unsigned>({{node,x}});
    
    /* ------------------------ */

    LogVar u_n_x;
    NodeIterator upNodes = _dah->getNodesUpFrom(node,true);
    u_n_x = _getValue(upNodes,n_x,unordered_map<Node*,unsigned>());

    /* ------------------------ */

    LogVar prodOfGamma;
    prodOfGamma = 1.0;

    unordered_set<Family*> downFamilies = node->getDownFamilies();
    for(Family* family: downFamilies) {

        LogVar gammaSum;

        NodeIterator nodesDownFam = _dah->getAllFromFamilyExceptFromNode(family,node,false);

        unordered_set<Node*> parentsNotNode = family->getParents();
        parentsNotNode.erase(node);
        MapIterator<Node*> parentsNotNode_xIterator = mapIteratorFromSet(parentsNotNode,_nHiddenStates);

        do {

            LogVar g_n_e_i_X;
            const unordered_map<Node*,unsigned> parentsNotNode_x = parentsNotNode_xIterator.getMap();
            g_n_e_i_X = _getValue(nodesDownFam,parentsNotNode_x,n_x);
            gammaSum += g_n_e_i_X;

        } while(parentsNotNode_xIterator.increment());

        prodOfGamma *= gammaSum;
    }

    /* ------------------------ */

    LogVar ans;
    ans = u_n_x*prodOfGamma;
    return ans;
}

LogVar FowrardsBackwards::getBValFor(Family* family, const unordered_map<Node*,unsigned>& X) {
        
    // using equation \beta_{n,e}(x) * \gamma_{n,e}(x,X\x)

    unordered_map<Node*,unsigned> X_ = X;

    pair<Node*,unsigned> firstElt = *(X_.begin());

    Node* node = firstElt.first;
    unsigned x = firstElt.second;
    unordered_map<Node*,unsigned> n_x = unordered_map<Node*,unsigned>({{node,x}});
    
    X_.erase(node);
    /* ------------------------ */

    LogVar b_n_e_i;
    NodeIterator allButFamily = _dah->getAllNodesExceptFromFamily(family,node,true);

    b_n_e_i = _getValue(allButFamily,n_x,unordered_map<Node*,unsigned>());

    /* ------------------------ */

    LogVar g_n_e_i_X_i;
    NodeIterator nodesDownFam = _dah->getAllFromFamilyExceptFromNode(family,node,false);
    g_n_e_i_X_i = _getValue(nodesDownFam,X_,n_x);

    /* ------------------------ */

    LogVar ans;
    ans = b_n_e_i*g_n_e_i_X_i;
    return ans;
}

LogVar FowrardsBackwards::getCValFor(Family* family, Node* child, const unordered_map<Node*,unsigned>& X, unsigned x) {
    
    // using equation <see notebook>

    unordered_map<Node*,unsigned> n_x = unordered_map<Node*,unsigned>({{child,x}});

    /* ------------------------ */

    LogVar bProd;
    bProd = 1.0;

    for(pair<Node*,unsigned> parentAndx: X) {
        
        Node* parent = parentAndx.first;
        unsigned j = parentAndx.second;
        const unordered_map<Node*,unsigned> np_j = unordered_map<Node*,unsigned>({{parent,j}});

        LogVar b_np_e_j;
        NodeIterator allButFamily = _dah->getAllNodesExceptFromFamily(family,parent,true);
        b_np_e_j = _getValue(allButFamily,np_j,unordered_map<Node*,unsigned>());

        bProd *= b_np_e_j;
    }

    /* ------------------------ */

    LogVar f_e_X_i = (*_transitionFunc)(family,child,X,x);
    LogVar g_n_i_ny = (*_emissionFunc)(child,x);

    /* ------------------------ */

    LogVar prodOfGamma;
    prodOfGamma = 1.0;

    unordered_set<Family*> downFamilies = child->getDownFamilies();
    for(Family* otherFamily: downFamilies) {

        LogVar gammaSum;

        NodeIterator nodesDownFam = _dah->getAllFromFamilyExceptFromNode(otherFamily,child,false);

        unordered_set<Node*> parentsNotNode = otherFamily->getParents();
        parentsNotNode.erase(child);
        MapIterator<Node*> parentsNotNode_xIterator = mapIteratorFromSet(parentsNotNode,_nHiddenStates);

        do {

            LogVar g_n_e_i_X;
            const unordered_map<Node*,unsigned> parentsNotNode_x = parentsNotNode_xIterator.getMap();
            g_n_e_i_X = _getValue(nodesDownFam,parentsNotNode_x,n_x);
            gammaSum += g_n_e_i_X;

        } while(parentsNotNode_xIterator.increment());

        prodOfGamma *= gammaSum;
    }

    /* ------------------------ */

    LogVar prodOfAlpha;
    prodOfAlpha = 1.0;

    unordered_set<Node*> siblings = family->getChildren();
    siblings.erase(child);

    for(Node* sibling: siblings) {

        LogVar a_ns_X;
        NodeIterator downFromSibling = _dah->getNodesDownFrom(sibling,true);
        a_ns_X = _getValue(downFromSibling,unordered_map<Node*,unsigned>(),X);

        prodOfAlpha *= a_ns_X;
    }

    /* ------------------------ */

    LogVar ans;
    ans = bProd*f_e_X_i*g_n_i_ny*prodOfGamma*prodOfAlpha;
    return ans;
}

LogVar FowrardsBackwards::getProbOfDAH() {
    return LogVar();
}
