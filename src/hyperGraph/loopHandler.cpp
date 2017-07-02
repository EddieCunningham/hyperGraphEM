#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/nodeIterator.h"



void LoopHandler::_analyzeDependencies() {

    Family* currentFamily = _nodeIterator.getFamilyAddedFrom();
    unordered_map<string,unordered_set<Node*>> hashToNodeSet = unordered_map<string,unordered_set<Node*>>();

    for(Node* node=_nodeIterator.getCurrent(); node!=nullptr; node=_nodeIterator.next()) {

        unordered_set<Family*> allFamilies = node->getFamilies();
        if(allFamilies.find(currentFamily) == allFamilies.end()) {
            break;
        }

        NodeIterator fromHere = NodeIterator::nodeIteratorFromOtherAndDirection(node,currentFamily,_nodeIterator,false);
        string hashFromHere = fromHere.getHash();
        if(hashToNodeSet.find(hashFromHere) == hashToNodeSet.end()) {
            hashToNodeSet[hashFromHere] = unordered_set<Node*>({node});
        }
        else {
            hashToNodeSet.at(hashFromHere).insert(node);
        }
    }

    for(auto& hashSetPair: hashToNodeSet) {
        unordered_set<Node*> dependentNodes = hashSetPair.second;
        if(dependentNodes.size() == 1) {
            continue;
        }
        _dependentNodes.push_back(vector<Node*>(dependentNodes.begin(),dependentNodes.end()));
    }
}

vector<Node*> LoopHandler::getDependentNodes(Node* node) {

    for(vector<Node*> nodeSet: _dependentNodes) {
        if(find(nodeSet.begin(),nodeSet.end(),node) != nodeSet.end()) {
            return nodeSet;
        }
    }
    return vector<Node*>();
}







