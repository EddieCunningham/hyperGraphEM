#include "/Users/Eddie/hyperGraphEM/src/helper/nestedLoop.h"
#include "/Users/Eddie/hyperGraphEM/src/EM/pedigreeEM/pedigreeHyperGraph.h"

MapIterator<Node*> mapIteratorFromSet(const unordered_set<Node*>& nodes, NumberOfHiddenStatesGetter* nHiddenStates) {

    unordered_map<Node*,unsigned> map = unordered_map<Node*,unsigned>();
    unordered_map<Node*,unsigned> maxVals = unordered_map<Node*,unsigned>();

    for(Node* node: nodes) {
        unsigned n = (*nHiddenStates)(node);
        map.insert({node,0});
        maxVals.insert({node,n});
    }

    MapIterator<Node*> mapIterator(map,maxVals);
    return mapIterator;
}

MapIterator<Person*> mapIteratorFromSet(const unordered_set<Person*>& nodes) {

    unordered_map<Person*,unsigned> map = unordered_map<Person*,unsigned>();
    unordered_map<Person*,unsigned> maxVals = unordered_map<Person*,unsigned>();

    for(Person* node: nodes) {
        unsigned n = node->getHiddenStatesN();
        map.insert({node,0});
        maxVals.insert({node,n});
    }

    MapIterator<Person*> mapIterator(map,maxVals);
    return mapIterator;
}



bool NestedLoop::increment(vector<unsigned int>& indices, const vector<unsigned int>& maxVals) {
    
    if(indices.size() != maxVals.size()) {
        failWithMessage(__FILE__,__LINE__,"indices isn't same size as maxVals");
    }

    for(int i=0; i<indices.size(); ++i) {

        unsigned int& index = indices.at(i);
        int maxVal = maxVals.at(i);
        if(maxVal == 0) {
            failWithMessage(__FILE__,__LINE__,"Can't have a maximum value of 0!!!!");
        }
        if(index < maxVal-1) {
            index += 1;
            return true;
        }
        index = 0;
    }
    return false;
}

