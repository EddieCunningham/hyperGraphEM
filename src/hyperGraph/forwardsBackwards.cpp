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

/* ------------------------------------------------ */


LogVar FowrardsBackwards::_alphaHelper(Node* node, unsigned x, const unordered_map<Node*,unsigned>& andedNodes, const unordered_map<Node*,unsigned>& conditionedNodes, const LoopHandler& loopHandler) {
    LogVar ans;

    

    return ans;
}

LogVar FowrardsBackwards::_betaHelper(Node* node, const unordered_map<Node*,unsigned>& parentMapping, const unordered_map<Node*,unsigned>& andedNodes, const unordered_map<Node*,unsigned>& conditionedNodes, const LoopHandler& loopHandler) {
    LogVar ans;



    return ans;
}




/* ------------------------------------------------ */

LogVar FowrardsBackwards::_uCase(const NodeIterator& yNodes, const unordered_map<Node*,unsigned>& andedNodes, const unordered_map<Node*,unsigned>& conditionedNodes) {
    LogVar ans;

    Node* child = yNodes.getCurrent();
    unsigned x = andedNodes.at(child);
    unordered_set<Family*> nextFamilies = yNodes.getQueuedFamilies();

    if(nextFamilies.size() == 0) {
        return _rootBaseCase(child,andedNodes,conditionedNodes);
    }
    if(nextFamilies.size() != 1) {
        failWithMessage(__FILE__,__LINE__,"Shouldn't have more than one family!");
    }

    LoopHandler loopHandler = LoopHandler(yNodes,false);

    unordered_map<Node*,unsigned> newAndedNodes = andedNodes;
    newAndedNodes.erase(child);

    Family* family = *(nextFamilies.begin());
    unordered_set<Node*> parents = family->getParents();
    unordered_set<Node*> children = family->getChildren();
    MapIterator<Node*> X = mapIteratorFromSet(parents,_nHiddenStates);

    LogVar emissionProb = _emissionFunc(child,x);

    do {

        LogVar transitionProb = _transitionFunc(family,child,X,x);
        if(transitionProb == 0.0) {
            continue;
        }
        unordered_map<Node*,unsigned> parentMapping = X.getMap();

        LogVar alphaProd;
        alphaProd = 1.0;

        for(auto& parentIndex: parentMapping) {
            Node* parentNode = parentIndex.first;
            unsigned j = parentIndex.second;

            LogVar alpha;
            alpha = _alphaHelper(parentNode,j,newAndedNodes,conditionedNodes,loopHandler);
            alphaProd *= alpha;
        }
        if(alphaProd == 0.0) {
            continue;
        }

        LogVar betaProd;
        betaProd = 1.0;

        for(Node* sibling: children) {
            if(sibling == child) {
                continue;
            }
            LogVar beta;
            beta = _betaHelper(sibling,parentMapping,newAndedNodes,conditionedNodes,loopHandler);
            betaProd *= beta;
        }

        ans += transitionProb*alphaProd*betaProd;

    } while(X.increment());

    ans *= emissionProb;

    return ans;
}
LogVar FowrardsBackwards::_vCase(const NodeIterator& yNodes, const unordered_map<Node*,unsigned>& andedNodes, const unordered_map<Node*,unsigned>& conditionedNodes) {
    LogVar ans;

    Family* currentFamily = yNodes.getFamilyAddedFrom();
    if(currentFamily == nullptr) {
        failWithMessage(__FILE__,__LINE__,"Dont think this can happen");
    }

    LoopHandler loopHandler = LoopHandler(yNodes,true);

    unordered_set<Node*> children = currentFamily->getChildren();

    unordered_map<Node*,int> conditionedParents = conditionedNodes;
    unordered_map<Node*,int> newConditionedNodes = conditionedNodes;
    for(auto& nodePair: conditionedNodes) {

        Node* potentialParent = nodePair.first;
        unsigned index = nodePair.second;
        unordered_set<Family*> downFamilies = potentialParent->getDownFamilies();

        if(downFamilies.find(currentFamily) == downFamilies.end()) {
            conditionedParents.erase(potentialParent);
            newConditionedNodes.insert(nodePair);
        }
    }

    unordered_set<Node*> unconditionedParents = currentFamily->getParents();
    for(auto& nodePair: conditionedParents) {
        Node* parent = nodePair.first;
        unconditionedParents.erase(parent);
    }

    MapIterator<Node*> X_ = mapIteratorFromSet(unconditionedParents,_nHiddenStates);

    do {

        unordered_map<Node*,unsigned> parentMapping = X_.getMap();

        LogVar alphaProd;
        alphaProd = 1.0;

        for(auto& parentIndex: parentMapping) {
            Node* parentNode = parentIndex.first;
            unsigned j = parentIndex.second;

            LogVar alpha;
            alpha = _alphaHelper(parentNode,j,andedNodes,newConditionedNodes,loopHandler);
            alphaProd *= alpha;
        }
        if(alphaProd == 0.0) {
            continue;
        }

        LogVar betaProd;
        betaProd = 1.0;

        for(Node* child: children) {
            LogVar beta;
            beta = _betaHelper(child,parentMapping,andedNodes,newConditionedNodes,loopHandler);
            betaProd *= beta;
        }

        ans += alphaProd*betaProd;

    } while(X_.increment());

    return ans;
}

/* ------------------------------------------------ */

LogVar FowrardsBackwards::_calcProb(const NodeIterator& yNodes, const unordered_map<Node*,unsigned>& andedNodes, const unordered_map<Node*,unsigned>& conditionedNodes) {
    
    LogVar ans;
    Node* current = yNodes.getCurrent();

    if(andedNodes.find(current) != andedNodes.end()) {
        ans = _uCase(yNodes,andedNodes,conditionedNodes);
    }
    else {
        ans = _vCase(yNodes,andedNodes,conditionedNodes);
    }
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
