#include "/Users/Eddie/hyperGraphEM/src/logVar/logVar.h"


void LogVar::_assign(double log_x) {
    _logAns = log_x;
}
void LogVar::operator =(const LogVar& a) {
    double log_x = a._logAns;
    _assign(log_x);
}
void LogVar::operator =(double a) {
    if(!_checkVal(a)) {
        string message = "LogVar can only handle values between 0 and 1.  a was: "+to_string(a);
        failWithMessage(__FILE__,__LINE__,message);
    }
    double log_x = _safeLog(a);
    _assign(log_x);
}
/* -------------------------------------------------------------------------------- */
const bool LogVar::_eq(double log_x) const {
    return _logEqual(_logAns,log_x);
}
const bool LogVar::operator ==(const LogVar& a) const {
    double log_x = a._logAns;
    return _eq(log_x);

}
const bool LogVar::operator ==(double a) const {
    if(!_checkVal(a)) {
        return false;
    }
    double log_x = _safeLog(a);
    return _eq(log_x);
}
/* -------------------------------------------------------------------------------- */
const bool LogVar::_lt(double log_x) const {
    if(_eq(log_x)) {
        return false;
    }
    if(_logAns == UNIQUE_ZERO_ID) {
        return true;
    }
    if(log_x == UNIQUE_ZERO_ID) {
        return false;
    }
    return _logAns < log_x;
}
const bool LogVar::operator <(const LogVar& a) const {
    double log_x = a._logAns;
    return _lt(log_x);
}
const bool LogVar::operator <(double a) const {
    if(a > 1.0 + PRECISION) {
        return true;
    }
    else if(a < 0.0 - PRECISION) {
        return false;
    }

    double log_x = _safeLog(a);
    return _lt(log_x);
}
/* -------------------------------------------------------------------------------- */
const bool LogVar::operator !=(const LogVar& a) const {
    return !((*this) == a);

}
const bool LogVar::operator !=(double a) const {
    return !((*this) == a);
}
/* -------------------------------------------------------------------------------- */
const bool LogVar::operator <=(const LogVar& a) const {
    return ((*this) < a) || ((*this) == a);
}
const bool LogVar::operator <=(double a) const {
    return ((*this) < a) || ((*this) == a);
}
/* -------------------------------------------------------------------------------- */
const bool LogVar::operator >(const LogVar& a) const {
    return !((*this) <= a);
}
const bool LogVar::operator >(double a) const {
    return !((*this) <= a);
}
/* -------------------------------------------------------------------------------- */
const bool LogVar::operator >=(const LogVar& a) const {
    return !((*this) < a);

}
const bool LogVar::operator >=(double a) const {
    return !((*this) < a);
}
/* -------------------------------------------------------------------------------- */



/* -------------------------------------------------------------------------------- */
void LogVar::operator +=(const LogVar& a) {
    _accumulatePositive(a._logAns);
}
void LogVar::operator +=(double a) {
    if(!_checkVal(a)) {
        string message = "LogVar can only handle values between 0 and 1.  a was: "+to_string(a);
        failWithMessage(__FILE__,__LINE__,message);
    }
    _accumulatePositive(_safeLog(a));
}
/* -------------------------------------------------------------------------------- */
LogVar LogVar::operator +(const LogVar& a) {
    LogVar ans;
    ans = (*this);
    ans += a;
    return ans;
}
LogVar LogVar::operator +(double a) {
    if(!_checkVal(a)) {
        string message = "LogVar can only handle values between 0 and 1.  a was: "+to_string(a);
        failWithMessage(__FILE__,__LINE__,message);
    }
    LogVar ans;
    ans = (*this);
    ans += a;
    return ans;
}
/* -------------------------------------------------------------------------------- */
void LogVar::operator -=(const LogVar& a) {
    _accumulateNegative(a._logAns);
}
void LogVar::operator -=(double a) {
    if(!_checkVal(a)) {
        string message = "LogVar can only handle values between 0 and 1.  a was: "+to_string(a);
        failWithMessage(__FILE__,__LINE__,message);
    }
    _accumulateNegative(_safeLog(a));
}
/* -------------------------------------------------------------------------------- */
LogVar LogVar::operator -(const LogVar& a) {
    LogVar ans;
    ans = (*this);
    ans -= a;
    return ans;
}
LogVar LogVar::operator -(double a) {
    if(!_checkVal(a)) {
        string message = "LogVar can only handle values between 0 and 1.  a was: "+to_string(a);
        failWithMessage(__FILE__,__LINE__,message);
    }
    LogVar ans;
    ans = (*this);
    ans -= a;
    return ans;
}
/* -------------------------------------------------------------------------------- */
void LogVar::_mul(double log_x) {
    if(_logAns == UNIQUE_ZERO_ID) {
        return;
    }
    if(log_x == UNIQUE_ZERO_ID) {
        _logAns = UNIQUE_ZERO_ID;
    }
    else {
        _logAns += log_x;
    }
}
void LogVar::operator *=(const LogVar& a) {
    double log_x = a._logAns;
    _mul(log_x);
}
void LogVar::operator *=(double a) {
    if(a < 0) {
        string message = "LogVar can only handle values between 0 and 1.  a was: "+to_string(a);
        failWithMessage(__FILE__,__LINE__,message);
    }
    double log_x = _safeLog(a,false);
    _mul(log_x);
}
/* -------------------------------------------------------------------------------- */
LogVar LogVar::operator *(const LogVar& a) {
    LogVar ans;
    ans = (*this);
    ans *= a;
    return ans;
}
LogVar LogVar::operator *(double a) {
    if(a < 0) {
        string message = "LogVar can only handle values between 0 and 1.  a was: "+to_string(a);
        failWithMessage(__FILE__,__LINE__,message);
    }
    LogVar ans;
    ans = (*this);
    ans *= a;
    return ans;
}

/* -------------------------------------------------------------------------------- */
void LogVar::_div(double log_x) {
    if(log_x == UNIQUE_ZERO_ID) {
        string message = "DIVIDING BY ZERO!";
        failWithMessage(__FILE__,__LINE__,message);
    }
    if(_logAns == UNIQUE_ZERO_ID) {
        return;
    }
    if(log_x < _logAns) {
        string message = "LogVar can only handle values between 0 and 1";
        failWithMessage(__FILE__,__LINE__,message);
    }
    _logAns -= log_x;
}
void LogVar::operator /=(const LogVar& a) {
    double log_x = a._logAns;
    _div(log_x);
}
void LogVar::operator /=(double a) {
    double log_x = _safeLog(a,false);
    _div(log_x);
}
/* -------------------------------------------------------------------------------- */
LogVar LogVar::operator /(const LogVar& a) {
    LogVar ans;
    ans = (*this);
    ans /= a;
    return ans;
}
LogVar LogVar::operator /(double a) {
    if(a < 0) {
        string message = "LogVar can only handle values between 0 and 1.  a was: "+to_string(a);
        failWithMessage(__FILE__,__LINE__,message);
    }
    LogVar ans;
    ans = (*this);
    ans /= a;
    return ans;
}









ostream& operator <<(ostream& os, const LogVar& lv) {  
    os << lv.val();
    return os;
}


