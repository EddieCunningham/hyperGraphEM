#include "/Users/Eddie/hyperGraphEM/src/helper/nestedLoop.h"


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

