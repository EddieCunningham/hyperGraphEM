#include <iostream>
#include "logVar.h"

void testAssert(double expected, logVar subject) {
    if(expected != subject) {
        string message = "got this wrong";
        failWithMessage(__FILE__,__LINE__,message);
    }
}

void test_assignLV() {
    double expected;
    logVar subject;


    testAssert(expected,subject);
}
void test_assignD() {
    double expected;
    logVar subject;


    testAssert(expected,subject);
}
void test_ltLV() {
    double expected;
    logVar subject;


    testAssert(expected,subject);
}
void test_ltD() {
    double expected;
    logVar subject;


    testAssert(expected,subject);
}
void test_lteLV() {
    double expected;
    logVar subject;


    testAssert(expected,subject);
}
void test_lteD() {
    double expected;
    logVar subject;


    testAssert(expected,subject);
}
void test_gtLV() {
    double expected;
    logVar subject;


    testAssert(expected,subject);
}
void test_gtD() {
    double expected;
    logVar subject;


    testAssert(expected,subject);
}
void test_gteLV() {
    double expected;
    logVar subject;


    testAssert(expected,subject);
}
void test_gteD() {
    double expected;
    logVar subject;


    testAssert(expected,subject);
}
void test_eqLV() {
    double expected;
    logVar subject;


    testAssert(expected,subject);
}
void test_eqD() {
    double expected;
    logVar subject;


    testAssert(expected,subject);
}
void test_neqLV() {
    double expected;
    logVar subject;


    testAssert(expected,subject);
}
void test_neqD() {
    double expected;
    logVar subject;


    testAssert(expected,subject);
}
void test_addLV() {
    double expected;
    logVar subject;


    testAssert(expected,subject);
}
void test_addD() {
    double expected;
    logVar subject;


    testAssert(expected,subject);
}
void test_incLV() {
    double expected;
    logVar subject;


    testAssert(expected,subject);
}
void test_incD() {
    double expected;
    logVar subject;


    testAssert(expected,subject);
}
void test_subLV() {
    double expected;
    logVar subject;


    testAssert(expected,subject);
}
void test_subD() {
    double expected;
    logVar subject;


    testAssert(expected,subject);
}
void test_decLV() {
    double expected;
    logVar subject;


    testAssert(expected,subject);
}
void test_decD() {
    double expected;
    logVar subject;


    testAssert(expected,subject);
}
void test_mulLV() {
    double expected;
    logVar subject;


    testAssert(expected,subject);
}
void test_mulD() {
    double expected;
    logVar subject;


    testAssert(expected,subject);
}
void test_mulincLV() {
    double expected;
    logVar subject;


    testAssert(expected,subject);
}
void test_mulincD() {
    double expected;
    logVar subject;


    testAssert(expected,subject);
}
void test_divLV() {
    double expected;
    logVar subject;


    testAssert(expected,subject);
}
void test_divD() {
    double expected;
    logVar subject;


    testAssert(expected,subject);
}
void test_divincLV() {
    double expected;
    logVar subject;


    testAssert(expected,subject);
}
void test_divincD() {
    double expected;
    logVar subject;


    testAssert(expected,subject);
}


void allLogVarTest() {
    test_assignLV();
    test_assignD();
    test_ltLV();
    test_ltD();
    test_lteLV();
    test_lteD();
    test_gtLV();
    test_gtD();
    test_gteLV();
    test_gteD();
    test_eqLV();
    test_eqD();
    test_neqLV();
    test_neqD();
    test_addLV();
    test_addD();
    test_incLV();
    test_incD();
    test_subLV();
    test_subD();
    test_decLV();
    test_decD();
    test_mulLV();
    test_mulD();
    test_mulincLV();
    test_mulincD();
    test_divLV();
    test_divD();
    test_divincLV();
    test_divincD();
}






