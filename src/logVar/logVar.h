#ifndef LOGVAR_H
#define LOGVAR_H


#define PRECISION pow(10,-14)
#define LOG_PRECISION log(pow(10,-14))
#define UNIQUE_ZERO_ID 1234.5678

#include "/Users/Eddie/hyperGraphEM/src/messages/errorMessages.h"
#include <cmath>

// this class will be used to deal with 
// arithmetic on small numbers.

// does normal arithmetic using log values 

// for the moment will only work on numbers between 0 and 1


using namespace std;

class LogVar {

    double _logAns = UNIQUE_ZERO_ID;

    double _safeLog(double x, bool checkVal = true) const;

    bool _checkLogVal(double log_x) const;
    bool _checkVal(double x) const;

    bool _logEqual(double log_x, double log_y) const;
    bool _equal(double log_x, double log_y) const;
    double __accumulatePositive(double log_x, double log_y);
    double __accumulateNegative(double log_x, double log_y);
    void _accumulatePositive(double log_x);
    void _accumulateNegative(double log_x);
    void _addPoint(int sign, double log_x);
    void _addPositiveLogPoint(double log_x);
    void _addNegativeLogPoint(double log_x);
    void _addZeroPoint();
    void _addPoint(double x);

    void _assign(double log_x);
    const bool _eq(double log_x) const;
    const bool _lt(double log_x) const;

    void _mul(double log_x);
    void _div(double log_x);


public:

    LogVar(){}

    void operator =(const LogVar& a);
    void operator =(double a);

    const bool operator <(const LogVar& a) const;
    const bool operator <(double a) const;

    const bool operator <=(const LogVar& a) const;
    const bool operator <=(double a) const;

    const bool operator >(const LogVar& a) const;
    const bool operator >(double a) const;

    const bool operator >=(const LogVar& a) const;
    const bool operator >=(double a) const;

    const bool operator ==(const LogVar& a) const;
    const bool operator ==(double a) const;

    const bool operator !=(const LogVar& a) const;
    const bool operator !=(double a) const;

    LogVar operator +(const LogVar& a);
    LogVar operator +(double a);

    void operator +=(const LogVar& a);
    void operator +=(double a);

    LogVar operator -(const LogVar& a);
    LogVar operator -(double a);

    void operator -=(const LogVar& a);
    void operator -=(double a);

    LogVar operator *(const LogVar& a);
    LogVar operator *(double a);

    void operator *=(const LogVar& a);
    void operator *=(double a);

    LogVar operator /(const LogVar& a);
    LogVar operator /(double a);

    void operator /=(const LogVar& a);
    void operator /=(double a);

    double val()const;

    /* TESTS */
    static void LogVarTests();
};


ostream& operator <<(ostream& os, const LogVar& lv);






#endif
