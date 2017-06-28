#include "/Users/Eddie/hyperGraphEM/src/tests/testMain.h"
#include "/Users/Eddie/hyperGraphEM/src/helper/nestedLoop.h"
#include <cmath>
#include <unordered_map>

void checkIfReset(const vector<unsigned>& indices) {
    
    bool nonZero = false;
    for(int i=0; i<indices.size(); ++i) {
        if(indices.at(i) != 0) {
            nonZero = true;
            break;
        }
    }
    if(nonZero) {
        failWithMessage(__FILE__,__LINE__,"Didnt reset incides!");
    }
}

void nestedLoopTest() {

    int nIndices = 5;
    int count = 6;
    vector<unsigned> indices(nIndices,0);
    vector<unsigned> maxVals(nIndices,count);

    int counter = 0;
    while(NestedLoop::increment(indices,maxVals)) {
        ++counter;
    }
    
    checkIfReset(indices);
    
    if(counter != pow(count,nIndices)-1) {
        failWithMessage(__FILE__,__LINE__,"wrong count");
    }
    
    counter = 0;
    indices = vector<unsigned>({0,0,0,0,0,0,0});
    maxVals = vector<unsigned>({1,2,3,4,3,2,1});
    while(NestedLoop::increment(indices,maxVals)) {
        ++counter;
    }
    if(counter != 144-1) {
        failWithMessage(__FILE__,__LINE__,"wrong count");
    }
}

void mapIteratorTest() {

    unordered_map<string,unsigned int> theMap({{"hello",0},{"this",0},{"is",0},{"a",0},{"test",0}});
    unordered_map<string,unsigned int> theMapMaxVals({{"hello",2},{"this",3},{"is",4},{"a",5},{"test",6}});
    MapIterator<string> mapIterator(theMap,theMapMaxVals);

    int counter = 0;
    do {
        int hello_index = mapIterator.getIndexFor("hello");
        int this_index = mapIterator.getIndexFor("this");
        int is_index = mapIterator.getIndexFor("is");
        int a_index = mapIterator.getIndexFor("a");
        int test_index = mapIterator.getIndexFor("test");

        cout << hello_index << " ";
        cout << this_index << " ";
        cout << is_index << " ";
        cout << a_index << " ";
        cout << test_index << endl;

        ++counter;

    } while(mapIterator.increment());

    if(counter != 720) {
        failWithMessage(__FILE__,__LINE__,"wrong count");
    }
}

void allNestedLoopTests() {

    nestedLoopTest();
    mapIteratorTest();
}


