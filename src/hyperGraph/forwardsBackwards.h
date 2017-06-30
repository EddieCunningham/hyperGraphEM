#ifndef FORWARDSBACKWARDS_H
#define FORWARDSBACKWARDS_H

#include "/Users/Eddie/hyperGraphEM/src/logVar/logVar.h"
#include "/Users/Eddie/hyperGraphEM/src/hyperGraph/hyperGraph.h"
#include "/Users/Eddie/hyperGraphEM/src/messages/errorMessages.h"
#include "/Users/Eddie/hyperGraphEM/src/helper/nestedLoop.h"
#include <unordered_map>
#include <vector>

class Person;
class NuclearFamily;
class Pedigree;
class PedigreeSoftEMOptimizer;

class NumberOfHiddenStatesGetter {
public:
    virtual unsigned operator()(Node* node) = 0;
};

class EmissionFunction {
public:
    virtual LogVar operator()(Node* node, unsigned x) = 0;
};

class TransitionFunction {
public:
    virtual LogVar operator()(Family* family, Node* child, const unordered_map<Node*,unsigned>& X, unsigned x) = 0;
};

class RootProbFunction {
public:
    virtual LogVar operator()(Node* node, unsigned x) = 0;
};

// will calculate P(Y) for subraphs of dah
class FowrardsBackwards {

    DirectedAcyclicHypergraph* _dah;

    NumberOfHiddenStatesGetter* _nHiddenStates;
    EmissionFunction* _emissionFunc;
    TransitionFunction* _transitionFunc;
    RootProbFunction* _rootProbFunc;

    unordered_map<string,LogVar> _storedAnswers;

    /* -------------- */

    MapIterator<Node*> _mapIteratorFromSet(const unordered_set<Node*>& nodes);

    /* -------------- */

    string _nodeMapHash(const unordered_map<Node*,unsigned>& nodeMap);
    string _iteratorAndConditionHash(const NodeIterator& iterator, const unordered_map<Node*,unsigned>& andedNodes, const unordered_map<Node*,unsigned>& conditionedNodes);
    void _storeSubProblemAns(const LogVar& ans, const NodeIterator& iterator, const unordered_map<Node*,unsigned>& andedNodes, const unordered_map<Node*,unsigned>& conditionedNodes);
    LogVar _getSubProblemAns(bool& found, const NodeIterator& iterator, const unordered_map<Node*,unsigned>& andedNodes, const unordered_map<Node*,unsigned>& conditionedNodes);

    /* -------------- */

    LogVar _rootBaseCase(Node* nodeY, const unordered_map<Node*,unsigned>& andedNodes, const unordered_map<Node*,unsigned>& conditionedNodes);
    LogVar _leafBaseCase(const unordered_map<Node*,unsigned>& andedNodes, const unordered_map<Node*,unsigned>& conditionedNodes);

    /* -------------- */

    LogVar _calcProb(NodeIterator iterator, const unordered_map<Node*,unsigned>& andedNodes, const unordered_map<Node*,unsigned>& conditionedNodes);
    LogVar _getValue(NodeIterator yNodes, const unordered_map<Node*,unsigned>& andedNodes, const unordered_map<Node*,unsigned>& conditionedNodes);

public:
    FowrardsBackwards(DirectedAcyclicHypergraph* dah, NumberOfHiddenStatesGetter* nHiddenStates, EmissionFunction* emissionFunc,TransitionFunction* transitionFunc,RootProbFunction* rootProbFunc) :
    _dah(dah),
    _nHiddenStates(nHiddenStates),
    _emissionFunc(emissionFunc),
    _transitionFunc(transitionFunc),
    _rootProbFunc(rootProbFunc) {}

    LogVar getAValFor(Node* node, unsigned x);
    LogVar getBValFor(Family* family, const unordered_map<Node*,unsigned>& X);
    LogVar getCValFor(Family* family, Node* child, const unordered_map<Node*,unsigned>& X, unsigned x);
    LogVar getProbOfDAH();

    /* TESTS */
    static void FowrardsBackwardsTests();
    static void getAValForTests();
    static void getBValForTests();
    static void getCValForTests();
    static void getProbOfDAHTests();
};







#endif
