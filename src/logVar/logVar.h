#ifndef LOGVAR_H
#define LOGVAR_H


#define PRECISION pow(10,-8)
#define LOG_PRECISION log(pow(10,-8))
#define UNIQUE_ZERO_ID 1234.5678


// this class will be used to deal with 
// arithmetic on small numbers.

// for the moment will only work on numbers between 0 and 1

class logVar {

    double _logAns = __DBL_MAX__;

public:

    void operator =(const logVar& a);
    void operator =(double a);
    void operator =(int a);

    bool operator <(const logVar& a);
    bool operator <(double a);
    bool operator <(int a);

    bool operator <=(const logVar& a);
    bool operator <=(double a);
    bool operator <=(int a);

    bool operator >(const logVar& a);
    bool operator >(double a);
    bool operator >(int a);

    bool operator >=(const logVar& a);
    bool operator >=(double a);
    bool operator >=(int a);

    bool operator ==(const logVar& a);
    bool operator ==(double a);
    bool operator ==(int a);

    bool operator !=(const logVar& a);
    bool operator !=(double a);
    bool operator !=(int a);

    logVar operator +(const logVar& a);
    logVar operator +(double a);
    logVar operator +(int a);

    logVar operator +=(const logVar& a);
    logVar operator +=(double a);
    logVar operator +=(int a);

    logVar operator -(const logVar& a);
    logVar operator -(double a);
    logVar operator -(int a);

    logVar operator -=(const logVar& a);
    logVar operator -=(double a);
    logVar operator -=(int a);

    logVar operator *(const logVar& a);
    logVar operator *(double a);
    logVar operator *(int a);

    logVar operator *=(const logVar& a);
    logVar operator *=(double a);
    logVar operator *=(int a);

    logVar operator /(const logVar& a);
    logVar operator /(double a);
    logVar operator /(int a);

    logVar operator /=(const logVar& a);
    logVar operator /=(double a);
    logVar operator /=(int a);




}















#endif