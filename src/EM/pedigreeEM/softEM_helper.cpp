#include "/Users/Eddie/hyperGraphEM/src/EM/pedigreeEM/softEM.h"


void sortMates(PersonWrapper* mateA, PersonWrapper* mateB, PersonWrapper* mother, PersonWrapper* father) {
    if(mateA == nullptr || mateB == nullptr) {
        mother = nullptr;
        father = nullptr;
        return;
    }

    Sex aSex = mateA->getSex();
    Sex BSex = mateB->getSex();
    if(aSex == female && bSex == male) {
        mother = mateA;
        father = mateB;
    }
    else if(aSex == male && bSex == female) {
        mother = mateB;
        father = mateA;
    }
    else {
        failWithMessage(__FILE__,__LINE__,"For now, am ignoring unknown,unknown parents");
    }

}