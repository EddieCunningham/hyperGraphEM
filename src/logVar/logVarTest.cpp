#include <iostream>


void testInit() {
    logVar a;
    cout << "Expect: 0 got: " << a << endl;
    a = 0.7;
    cout << "Expect: 0.7 got: " << a << endl;
    a = 6;
    cout << "Expect: INVALID got: " << a << endl;
}

void testAdd() {
    logVar a;
    logVar b;

    logVar c = a + b;
    cout << "Expect: 0 got: " << c << endl;

    a = 0.123;
    c = a + b;
    cout << "Expect 0.123 got: " << c << endl;

    c = c + 0.1;
    cout << "Expect 0.223 got: " << c << endl;

    c += 0.1;
    cout << "Expect 0.323 got: " << c << endl;
}

void testSubtract() {
    logVar a;
    logVar b;

    logVar c = a - b;
    cout << "Expect: 0 got: " << c << endl;

    a = 0.123;
    c = a - b;
    cout << "Expect 0.123 got: " << c << endl;

    c = c - 0.1;
    cout << "Expect 0.023 got: " << c << endl;

    c -= 0.01;
    cout << "Expect 0.313 got: " << c << endl;
}

void testMultiply() {
    logVar a = 0.2;
    logVar b = 0.1;

    a = a*b;
    cout << "Expect 0.02 got: " << a << endl;

    a *= 0.1;
    cout << "Expect 0.002 got: " << a << endl;

    a *= 0.1;
    a *= 0.1;
    a *= b;
    cout << "Expect 0.000002 got: " << a << endl;
}

void testDivide() {
    logVar a = 0.1;
    logVar b = 0.2;

    a = a/b;
    cout << "Expect 0.5 got: " << a << endl;

    a /= 1.0;
    cout << "Expect 0.5 got: " << a << endl;
}

void testRelation() {
    logVar a = 0.1;
    logVar b = 0.2;
    logVar c = 0.1;

    bool t1 = a < b;
    cout << "Expected true got: " << t1 << endl;

    bool t2 = b > a;
    cout << "Expected false got: " << t2 << endl;

    bool t3 = a <= b;
    cout << "Expected true got: " << t3 << endl;

    bool t4 = b >= a;
    cout << "Expected false got: " << t4 << endl;

    bool t5 = a == c;
    cout << "Expected true got: " << t5 << endl;

    bool t6 = b != c;
    cout << "Expected true got: " << t6 << endl;

}


int main() {
    testInit()
    testAdd()
    testSubtract()
    testMultiply()
    testDivide()
    testRelation()
}






