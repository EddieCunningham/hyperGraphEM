#ifndef NESTEDLOOP_H
#define NESTEDLOOP_H

#include <unordered_map>
#include <vector>
#include "/Users/Eddie/hyperGraphEM/src/messages/errorMessages.h"
//#include "/Users/Eddie/hyperGraphEM/src/EM/pedigreeEM/pedigreeHyperGraph.h"
#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraph.h"
#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/forwardsBackwards.h"

using namespace std;


class NodeIterator;
template <class T>
class MapIterator;
class Node;
class Person;
class NumberOfHiddenStatesGetter;

MapIterator<Node*> mapIteratorFromSet(const unordered_set<Node*>& nodes, NumberOfHiddenStatesGetter* nHiddenStates);
MapIterator<Person*> mapIteratorFromSet(const unordered_set<Person*>& nodes);


class NestedLoop {
public:
    static bool increment(vector<unsigned int>& indices, const vector<unsigned int>& maxVals);
};

template <class T>
class MapIterator {

    vector<T> _orderedKeys;
    unordered_map<T,unsigned int>& _map;
    unordered_map<T,unsigned int>& _maxVals;

public:
    MapIterator(unordered_map<T,unsigned int>& map, unordered_map<T,unsigned int>& maxVals);
    int getIndexFor(T key);
    const unordered_map<T,unsigned int> getMap();
    bool increment();

    /* TESTS */
    static void MapIteratorTests();
    static void getIndexForTests();
    static void getMapTests();
    static void incrementTests();
};


template <class T>
MapIterator<T>::MapIterator(unordered_map<T,unsigned int>& map, unordered_map<T,unsigned int>& maxVals):
_map(map),
_maxVals(maxVals) {
    
    _orderedKeys = vector<T>();
    for(pair<const T,unsigned int>& keyVal: map) {
        
        T key = keyVal.first;
        _orderedKeys.push_back(key);
    }
}

template <class T>
int MapIterator<T>::getIndexFor(T key) {
    return _map.at(key);
}

template <class T>
const unordered_map<T,unsigned int> MapIterator<T>::getMap() {
    return _map;
}

template <class T>
bool MapIterator<T>::increment() {
    
    for(int i=0; i<_orderedKeys.size(); ++i) {
        
        T key = _orderedKeys.at(i);
        unsigned int& index = _map.at(key);
        int maxVal = _maxVals.at(key);
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

template <class T>
void MapIterator<T>::MapIteratorTests() {
    failWithMessage(__FILE__,__LINE__,"assert statement");
}

template <class T>
void MapIterator<T>::getIndexForTests() {
    failWithMessage(__FILE__,__LINE__,"assert statement");
}

template <class T>
void MapIterator<T>::getMapTests() {
    failWithMessage(__FILE__,__LINE__,"assert statement");
}

template <class T>
void MapIterator<T>::incrementTests() {
    failWithMessage(__FILE__,__LINE__,"assert statement");
}



#endif
