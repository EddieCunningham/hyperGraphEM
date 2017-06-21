#ifndef LOGVAR_H
#define LOGVAR_H


#define PRECISION pow(10,-8)
#define LOG_PRECISION log(pow(10,-8))
#define UNIQUE_ZERO_ID 1234.5678

#include "/Users/Eddie/hyperGraphEM/src/messages/errorMessages.h"

// this class will be used to deal with 
// arithmetic on small numbers.

// does normal arithmetic using log values 

// for the moment will only work on numbers between 0 and 1

class logVar {

    double _logAns = UNIQUE_ZERO_ID;

    bool _checkLogVal(double log_x);
    bool _checkVal(double x);

    bool _logEqual(double log_x, double log_y);
    bool _equal(double log_x, double log_y);
    double __accumulatePositive(double log_x, double log_y);
    double __accumulateNegative(double log_x, double log_y);
    void _accumulatePositive(double log_x);
    void _accumulateNegative(double log_x);
    void _addPoint(int sign, double log_x);
    void _addPositiveLogPoint(double log_x);
    void _addNegativeLogPoint(double log_x);
    void _addZeroPoint();
    void _addPoint(double x);
    double _getNormalAns();

public:

    logVar(){}

    void operator =(const logVar& a);
    void operator =(double a);

    bool operator <(const logVar& a);
    bool operator <(double a);

    bool operator <=(const logVar& a);
    bool operator <=(double a);

    bool operator >(const logVar& a);
    bool operator >(double a);

    bool operator >=(const logVar& a);
    bool operator >=(double a);

    bool operator ==(const logVar& a);
    bool operator ==(double a);

    bool operator !=(const logVar& a);
    bool operator !=(double a);

    logVar operator +(const logVar& a);
    logVar operator +(double a);

    logVar operator +=(const logVar& a);
    logVar operator +=(double a);

    logVar operator -(const logVar& a);
    logVar operator -(double a);

    logVar operator -=(const logVar& a);
    logVar operator -=(double a);

    logVar operator *(const logVar& a);
    logVar operator *(double a);

    logVar operator *=(const logVar& a);
    logVar operator *=(double a);

    logVar operator /(const logVar& a);
    logVar operator /(double a);

    logVar operator /=(const logVar& a);
    logVar operator /=(double a);
};


extern void allLogVarTest();












#endif
