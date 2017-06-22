#include <iostream>
#include "/Users/Eddie/hyperGraphEM/src/logVar/logVar.h"
// #include "/Users/Eddie/hyperGraphEM/src/logVar/logVar.h"

void testAssert(double expected, logVar x) {
    if(x != expected) {
        string message = "got this wrong";
        cout << x << endl;
        failWithMessage(__FILE__,__LINE__,message);
    }
}

void testAssert(double expected, double x) {
    if(expected != x) {
        string message = "got this wrong";
        cout << x << endl;
        failWithMessage(__FILE__,__LINE__,message);
    }
}

void testAssert(bool expected, bool x) {
    if(expected != x) {
        string message = "got this comparison wrong";
        cout << x << endl;
        failWithMessage(__FILE__,__LINE__,message);
    }
}

void test_assignLV() {
    logVar x;
    logVar a;
    a = 0.3;
    x = a;
    testAssert(0.3,x);


    logVar b;
    x = b;
    testAssert(0.0,x);

    logVar c;
    c = 0.0;
    x = c;
    testAssert(0.0,x);

    logVar d;
    d = 1.0;
    x = d;
    testAssert(1.0,x);
}
void test_assignD() {
    logVar x;
    x = 0.3;
    testAssert(0.3,x);

    x = 0.0;
    testAssert(0.0,x);

    x = 1.0;
    testAssert(1.0,x);
}
void test_ltLV() {
    logVar x;
    bool a = x < 0.3;
    testAssert(true,a);

    logVar b_1;
    b_1 = 0.0;
    a = x < b_1;
    testAssert(false,a);

    x = 0.3;
    logVar b_2;
    b_2 = 1.0;
    a = x < b_2;
    testAssert(true,a);

    logVar b_3;
    b_3 = 0.3;
    a = x < b_3;
    testAssert(false,a);

    logVar b_5;
    b_5 = 0.1;
    a = x < b_5;
    testAssert(false,a);

    logVar b_6;
    b_6 = 0.0;
    a = x < b_6;
    testAssert(false,a);

}
void test_ltD() {
    logVar x;
    bool a = x < 0.3;
    testAssert(true,a);

    a = x < 0.0;
    testAssert(false,a);

    x = 0.3;
    a = x < 1.0;
    testAssert(true,a);

    a = x < 0.3;
    testAssert(false,a);

    a = x < 1.5;
    testAssert(true,a);

    a = x < 0.1;
    testAssert(false,a);

    a = x < 0.0;
    testAssert(false,a);

    a = x < -2;
    testAssert(false,a);
}
void test_lteLV() {
    logVar x;
    bool a = x <= 0.3;
    testAssert(true,a);

    logVar b_1;
    b_1 = 0.0;
    a = x <= b_1;
    testAssert(true,a);

    x = 0.3;
    logVar b_2;
    b_2 = 1.0;
    a = x <= b_2;
    testAssert(true,a);

    logVar b_3;
    b_3 = 0.3;
    a = x <= b_3;
    testAssert(true,a);

    logVar b_5;
    b_5 = 0.1;
    a = x <= b_5;
    testAssert(false,a);

    logVar b_6;
    b_6 = 0.0;
    a = x <= b_6;
    testAssert(false,a);

}
void test_lteD() {
    logVar x;
    bool a = x <= 0.3;
    testAssert(true,a);

    a = x <= 0.0;
    testAssert(true,a);

    x = 0.3;
    a = x <= 1.0;
    testAssert(true,a);

    a = x <= 0.3;
    testAssert(true,a);

    a = x <= 1.5;
    testAssert(true,a);

    a = x <= 0.1;
    testAssert(false,a);

    a = x <= 0.0;
    testAssert(false,a);

    a = x <= -2;
    testAssert(false,a);
}
void test_gtLV() {
    logVar x;
    bool a = x > 0.3;
    testAssert(false,a);

    logVar b_1;
    b_1 = 0.0;
    a = x > b_1;
    testAssert(false,a);

    x = 0.3;
    logVar b_2;
    b_2 = 1.0;
    a = x > b_2;
    testAssert(false,a);

    logVar b_3;
    b_3 = 0.3;
    a = x > b_3;
    testAssert(false,a);

    logVar b_5;
    b_5 = 0.1;
    a = x > b_5;
    testAssert(true,a);

    logVar b_6;
    b_6 = 0.0;
    a = x > b_6;
    testAssert(true,a);

}
void test_gtD() {
    logVar x;
    bool a = x > 0.3;
    testAssert(false,a);

    a = x > 0.0;
    testAssert(false,a);

    x = 0.3;
    a = x > 1.0;
    testAssert(false,a);

    a = x > 0.3;
    testAssert(false,a);

    a = x > 1.5;
    testAssert(false,a);

    a = x > 0.1;
    testAssert(true,a);

    a = x > 0.0;
    testAssert(true,a);

    a = x > -2;
    testAssert(true,a);
}
void test_gteLV() {
    logVar x;
    bool a = x >= 0.3;
    testAssert(false,a);

    logVar b_1;
    b_1 = 0.0;
    a = x >= b_1;
    testAssert(true,a);

    x = 0.3;
    logVar b_2;
    b_2 = 1.0;
    a = x >= b_2;
    testAssert(false,a);

    logVar b_3;
    b_3 = 0.3;
    a = x >= b_3;
    testAssert(true,a);

    logVar b_5;
    b_5 = 0.1;
    a = x >= b_5;
    testAssert(true,a);

    logVar b_6;
    b_6 = 0.0;
    a = x >= b_6;
    testAssert(true,a);

}
void test_gteD() {
    logVar x;
    bool a = x >= 0.3;
    testAssert(false,a);

    a = x >= 0.0;
    testAssert(true,a);

    x = 0.3;
    a = x >= 1.0;
    testAssert(false,a);

    a = x >= 0.3;
    testAssert(true,a);

    a = x >= 1.5;
    testAssert(false,a);

    a = x >= 0.1;
    testAssert(true,a);

    a = x >= 0.0;
    testAssert(true,a);

    a = x >= -2;
    testAssert(true,a);
}
void test_eqLV() {
    logVar x;
    logVar a;
    a = 0.0;
    bool comp = x == a;
    testAssert(true,comp);

    a = 0.3;
    comp = x == a;
    testAssert(false,comp);

    x = 0.3;
    comp = x == a;
    testAssert(true,comp);

    a = 0.0;
    comp = x == a;
    testAssert(false,comp);
}
void test_eqD() {
    logVar x;
    double a = 0.0;
    bool comp = x == a;
    testAssert(true,comp);

    a = 0.3;
    comp = x == a;
    testAssert(false,comp);

    x = 0.3;
    comp = x == a;
    testAssert(true,comp);

    a = 0.0;
    comp = x == a;
    testAssert(false,comp);
}
void test_neqLV() {
    logVar x;
    logVar a;
    a = 0.0;
    bool comp = x != a;
    testAssert(false,comp);

    a = 0.3;
    comp = x != a;
    testAssert(true,comp);

    x = 0.3;
    comp = x != a;
    testAssert(false,comp);

    a = 0.0;
    comp = x != a;
    testAssert(true,comp);
}
void test_neqD() {
    logVar x;
    double a = 0.0;
    bool comp = x != a;
    testAssert(false,comp);

    a = 0.3;
    comp = x != a;
    testAssert(true,comp);

    x = 0.3;
    comp = x != a;
    testAssert(false,comp);

    a = 0.0;
    comp = x != a;
    testAssert(true,comp);
}
void test_addLV() {
    logVar x;
    logVar a;
    logVar b;
    b = x + a;
    testAssert(0,b);

    a = 0.2;
    b = x + a;
    testAssert(0.2,b);
    x = b;

    a = 0.0;
    b = x + a;
    testAssert(0.2,b);

    x = 0.9;
    a = 0.1;
    b = x + a;
    testAssert(1.0,b);
}
void test_addD() {
    logVar x;
    double a = 0.0;
    logVar b;
    b = x + a;
    testAssert(0,b);

    a = 0.2;
    b = x + a;
    testAssert(0.2,b);
    x = b;

    a = 0.0;
    b = x + a;
    testAssert(0.2,b);

    x = 0.9;
    a = 0.1;
    b = x + a;
    testAssert(1.0,b);
}
void test_incLV() {
    logVar x;
    logVar a;
    x += a;
    testAssert(0,x);

    a = 0.2;
    x += a;
    testAssert(0.2,x);

    a = 0.0;
    x += a;
    testAssert(0.2,x);

    x = 0.9;
    a = 0.1;
    x += a;
    testAssert(1.0,x);
}
void test_incD() {
    logVar x;
    double a = 0.0;
    x += a;
    testAssert(0,x);

    a = 0.2;
    x += a;
    testAssert(0.2,x);

    
    a = 0.0;
    x += a;
    testAssert(0.2,x);

    x = 0.9;
    a = 0.1;
    x += a;
    testAssert(1.0,x);
}
void test_subLV() {
    logVar x;
    logVar a;
    logVar b;
    b = a - x;
    testAssert(0,b);

    x = 1.0;
    a = 0.2;
    b = x - a;
    testAssert(0.8,b);
    x = b;

    a = 1.0;
    b = a - x;
    testAssert(0.2,b);

    x = 0.9;
    a = 0.1;
    b = x - a;
    testAssert(0.8,b);

    a = 0.0;
    b = x - a;
    testAssert(0.9,b);
}
void test_subD() {
    logVar x;
    double a = 0.0;
    logVar b;
    b = x - a;
    testAssert(0,b);
    
    x = 1.0;
    a = 0.2;
    b = x - a;
    testAssert(0.8,b);
    x = b;
    
    
    x = 0.9;
    a = 0.1;
    b = x - a;
    testAssert(0.8,b);
    
    a = 0.0;
    b = x - a;
    testAssert(0.9,b);
}
void test_decLV() {
    logVar x;
    logVar a;
    x -= a;
    testAssert(0,x);

    x = 1.0;
    a = 0.2;
    x -= a;
    testAssert(0.8,x);

    a = 0.0;
    x -= a;

    x = 0.9;
    a = 0.1;
    x -= a;
    testAssert(0.8,x);

    a = 0.0;
    x -= a;
    testAssert(0.8,x);
}
void test_decD() {
    logVar x;
    double a = 0.0;
    x -= a;
    testAssert(0,x);

    x = 1.0;
    a = 0.2;
    x -= a;
    testAssert(0.8,x);

    a = 0.0;
    x -= a;

    x = 0.9;
    a = 0.1;
    x -= a;
    testAssert(0.8,x);

    a = 0.0;
    x -= a;
    testAssert(0.8,x);
}
void test_mulLV() {
    logVar x;
    logVar a;
    logVar b;
    b = x * a;
    testAssert(0,b);

    a = 1.0;
    b = x * a;
    testAssert(0,b);

    x = 0.3;
    b = x * a;
    testAssert(0.3,b);

    x = 0.3;
    a = 0.3;
    b = x * a;
    testAssert(0.09,b);

    x = 0.1;
    a = 0.1;
    b = x*a*a*a*a*a*a*a*a*a;
    testAssert(pow(10,-10),b);
}
void test_mulD() {
    logVar x;
    double a = 0.0;
    logVar b;
    b = x * a;
    testAssert(0,b);

    a = 1.0;
    b = x * a;
    testAssert(0,b);

    x = 0.3;
    b = x * a;
    testAssert(0.3,b);

    x = 0.3;
    a = 0.3;
    b = x * a;
    testAssert(0.09,b);

    x = 0.1;
    a = 0.1;
    b = x*a*a*a*a*a*a*a*a*a;
    testAssert(pow(10,-10),b);
}
void test_mulincLV() {
    logVar x;
    logVar a;
    x *= a;
    testAssert(0,x);

    a = 1.0;
    x *= a;
    testAssert(0,x);

    x = 0.3;
    x *= a;
    testAssert(0.3,x);

    x = 0.3;
    a = 0.3;
    x *= a;
    testAssert(0.09,x);
}
void test_mulincD() {
    logVar x;
    double a = 0.0;
    x *= a;
    testAssert(0,x);

    a = 1.0;
    x *= a;
    testAssert(0,x);

    x = 0.3;
    x *= a;
    testAssert(0.3,x);

    x = 0.3;
    a = 0.3;
    x *= a;
    testAssert(0.09,x);
}
void test_divLV() {

    logVar x;
    logVar a;
    a = 0.4;
    logVar b;
    b = x / a;
    testAssert(0.0,b);

    a = 1.0;
    b = x / a;
    testAssert(0.0,b);

    x = 0.2;
    a = 0.4;
    b = x / a;
    testAssert(0.5,b);

}
void test_divD() {

    logVar x;
    double a = 0.4;
    logVar b = x / a;
    testAssert(0.0,b);

    a = 1.0;
    b = x / a;
    testAssert(0.0,b);

    a = 1234;
    b = x / a;
    testAssert(0.0,b);

    x = 0.2;
    a = 0.4;
    b = x / a;
    testAssert(0.5,b);
    
    x = 0.2;
    a = 12345;
    b = x / a;
}
void test_divincLV() {
    logVar x;
    logVar a;
    a = 0.4;
    x /= a;
    testAssert(0.0,x);

    a = 1.0;
    x /= a;
    testAssert(0.0,x);

    x = 0.2;
    a = 0.4;
    x /= a;
    testAssert(0.5,x);
}
void test_divincD() {
    logVar x;
    double a = 0.4;
    x /= a;
    testAssert(0.0,x);

    a = 1.0;
    x /= a;
    testAssert(0.0,x);

    x = 0.2;
    a = 0.4;
    x /= a;
    testAssert(0.5,x);

}


void allLogVarTests() {
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






