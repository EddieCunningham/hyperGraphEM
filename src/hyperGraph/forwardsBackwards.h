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


// will calculate P(Y) for subraphs of dah
class FowrardsBackwards {

    DirectedAcyclicHypergraph* _dah;

    NumberOfHiddenStatesGetter* _nHiddenStates;
    EmissionFunction* _emissionFunc;
    TransitionFunction* _transitionFunc;
    RootProbFunction* _rootProbFunc;

    unordered_map<string,LogVar> _storedAnswers;

    /* -------------- */

    string _nodeMapHash(const unordered_map<Node*,unsigned>& nodeMap);
    string _iteratorAndConditionHash(const NodeIterator& iterator, const unordered_map<Node*,unsigned>& andedNodes, const unordered_map<Node*,unsigned>& conditionedNodes);
    void _storeSubProblemAns(const LogVar& ans, const NodeIterator& iterator, const unordered_map<Node*,unsigned>& andedNodes, const unordered_map<Node*,unsigned>& conditionedNodes);
    LogVar _getSubProblemAns(bool& found, const NodeIterator& iterator, const unordered_map<Node*,unsigned>& andedNodes, const unordered_map<Node*,unsigned>& conditionedNodes);

    /* -------------- */

    LogVar _rootBaseCase(Node* nodeY, const unordered_map<Node*,unsigned>& andedNodes, const unordered_map<Node*,unsigned>& conditionedNodes);
    LogVar _leafBaseCase(const unordered_map<Node*,unsigned>& andedNodes, const unordered_map<Node*,unsigned>& conditionedNodes);

    /* -------------- */

    LogVar _alphaHelper(Node* node, unsigned x, const unordered_map<Node*,unsigned>& andedNodes, const unordered_map<Node*,unsigned>& conditionedNodes, const LoopHandler& loopHandler);
    LogVar _betaHelper(Node* node, const unordered_map<Node*,unsigned>& parentMapping, const unordered_map<Node*,unsigned>& andedNodes, const unordered_map<Node*,unsigned>& conditionedNodes, const LoopHandler& loopHandler);

    /* -------------- */

    LogVar _uCase(const NodeIterator& yNodes, const unordered_map<Node*,unsigned>& andedNodes, const unordered_map<Node*,unsigned>& conditionedNodes);
    LogVar _vCase(const NodeIterator& yNodes, const unordered_map<Node*,unsigned>& andedNodes, const unordered_map<Node*,unsigned>& conditionedNodes);

    /* -------------- */

    LogVar _calcProb(const NodeIterator& yNodes, const unordered_map<Node*,unsigned>& andedNodes, const unordered_map<Node*,unsigned>& conditionedNodes);
    LogVar _getValue(const NodeIterator& yNodes, const unordered_map<Node*,unsigned>& andedNodes, const unordered_map<Node*,unsigned>& conditionedNodes);

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
