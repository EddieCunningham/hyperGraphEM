#include <iostream>
#include "/Users/Eddie/hyperGraphEM/src/logVar/logVar.h"
#include "/Users/Eddie/hyperGraphEM/src/tests/testMain.h"

void testAssert(double expected, LogVar x) {
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
    LogVar x;
    LogVar a;
    a = 0.3;
    x = a;
    testAssert(0.3,x);


    LogVar b;
    x = b;
    testAssert(0.0,x);

    LogVar c;
    c = 0.0;
    x = c;
    testAssert(0.0,x);

    LogVar d;
    d = 1.0;
    x = d;
    testAssert(1.0,x);
}
void test_assignD() {
    LogVar x;
    x = 0.3;
    testAssert(0.3,x);

    x = 0.0;
    testAssert(0.0,x);

    x = 1.0;
    testAssert(1.0,x);
}
void test_ltLV() {
    LogVar x;
    bool a = x < 0.3;
    testAssert(true,a);

    LogVar b_1;
    b_1 = 0.0;
    a = x < b_1;
    testAssert(false,a);

    x = 0.3;
    LogVar b_2;
    b_2 = 1.0;
    a = x < b_2;
    testAssert(true,a);

    LogVar b_3;
    b_3 = 0.3;
    a = x < b_3;
    testAssert(false,a);

    LogVar b_5;
    b_5 = 0.1;
    a = x < b_5;
    testAssert(false,a);

    LogVar b_6;
    b_6 = 0.0;
    a = x < b_6;
    testAssert(false,a);

}
void test_ltD() {
    LogVar x;
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
    LogVar x;
    bool a = x <= 0.3;
    testAssert(true,a);

    LogVar b_1;
    b_1 = 0.0;
    a = x <= b_1;
    testAssert(true,a);

    x = 0.3;
    LogVar b_2;
    b_2 = 1.0;
    a = x <= b_2;
    testAssert(true,a);

    LogVar b_3;
    b_3 = 0.3;
    a = x <= b_3;
    testAssert(true,a);

    LogVar b_5;
    b_5 = 0.1;
    a = x <= b_5;
    testAssert(false,a);

    LogVar b_6;
    b_6 = 0.0;
    a = x <= b_6;
    testAssert(false,a);

}
void test_lteD() {
    LogVar x;
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
    LogVar x;
    bool a = x > 0.3;
    testAssert(false,a);

    LogVar b_1;
    b_1 = 0.0;
    a = x > b_1;
    testAssert(false,a);

    x = 0.3;
    LogVar b_2;
    b_2 = 1.0;
    a = x > b_2;
    testAssert(false,a);

    LogVar b_3;
    b_3 = 0.3;
    a = x > b_3;
    testAssert(false,a);

    LogVar b_5;
    b_5 = 0.1;
    a = x > b_5;
    testAssert(true,a);

    LogVar b_6;
    b_6 = 0.0;
    a = x > b_6;
    testAssert(true,a);

}
void test_gtD() {
    LogVar x;
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
    LogVar x;
    bool a = x >= 0.3;
    testAssert(false,a);

    LogVar b_1;
    b_1 = 0.0;
    a = x >= b_1;
    testAssert(true,a);

    x = 0.3;
    LogVar b_2;
    b_2 = 1.0;
    a = x >= b_2;
    testAssert(false,a);

    LogVar b_3;
    b_3 = 0.3;
    a = x >= b_3;
    testAssert(true,a);

    LogVar b_5;
    b_5 = 0.1;
    a = x >= b_5;
    testAssert(true,a);

    LogVar b_6;
    b_6 = 0.0;
    a = x >= b_6;
    testAssert(true,a);

}
void test_gteD() {
    LogVar x;
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
    LogVar x;
    LogVar a;
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
    LogVar x;
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
    LogVar x;
    LogVar a;
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
    LogVar x;
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
    LogVar x;
    LogVar a;
    LogVar b;
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
    LogVar x;
    double a = 0.0;
    LogVar b;
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
    LogVar x;
    LogVar a;
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
    LogVar x;
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
    LogVar x;
    LogVar a;
    LogVar b;
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
    LogVar x;
    double a = 0.0;
    LogVar b;
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
    LogVar x;
    LogVar a;
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
    LogVar x;
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
    LogVar x;
    LogVar a;
    LogVar b;
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
    LogVar x;
    double a = 0.0;
    LogVar b;
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
    LogVar x;
    LogVar a;
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
    LogVar x;
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

    LogVar x;
    LogVar a;
    a = 0.4;
    LogVar b;
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

    LogVar x;
    double a = 0.4;
    LogVar b = x / a;
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
    LogVar x;
    LogVar a;
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
    LogVar x;
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






