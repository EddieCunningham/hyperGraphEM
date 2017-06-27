#include "/Users/Eddie/hyperGraphEM/src/EM/pedigreeEM/softEM.h"


void sortMates(Person* mateA, Person* mateB, Person* mother, Person* father) {
    if(mateA == nullptr || mateB == nullptr) {
        mother = nullptr;
        father = nullptr;
        return;
    }

    Sex aSex = mateA->getSex();
    Sex bSex = mateB->getSex();
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
