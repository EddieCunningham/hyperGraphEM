#include "/Users/Eddie/hyperGraphEM/src/logVar/logVar.h"


void logVar::_assign(double log_x) {
    _logAns = log_x;
}
void logVar::operator =(const logVar& a) {
    double log_x = a._logAns;
    _assign(a._logAns);
}
void logVar::operator =(double a) {
    if(!_checkVal(a)) {
        string message = "logVar can only handle values between 0 and 1.  a was: "+to_string(a);
        failWithMessage(__FILE__,__LINE__,message);
    }
    double log_x = _safeLog(a);
    _assign(log_x);
}
/* -------------------------------------------------------------------------------- */
bool logVar::_eq(double log_x) {
    return _logEqual(_logAns,log_x);
}
bool logVar::operator ==(const logVar& a) {
    double log_x = a._logAns;
    return _eq(log_x);

}
bool logVar::operator ==(double a) {
    if(!_checkVal(a)) {
        return false;
    }
    double log_x = _safeLog(a);
    return _eq(log_x);
}
/* -------------------------------------------------------------------------------- */
bool logVar::_lt(double log_x) {
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
bool logVar::operator <(const logVar& a) {
    double log_x = a._logAns;
    return _lt(log_x);
}
bool logVar::operator <(double a) {
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
bool logVar::operator !=(const logVar& a) {
    return !((*this) == a);

}
bool logVar::operator !=(double a) {
    return !((*this) == a);
}
/* -------------------------------------------------------------------------------- */
bool logVar::operator <=(const logVar& a) {
    return ((*this) < a) || ((*this) == a);
}
bool logVar::operator <=(double a) {
    return ((*this) < a) || ((*this) == a);
}
/* -------------------------------------------------------------------------------- */
bool logVar::operator >(const logVar& a) {
    return !((*this) <= a);
}
bool logVar::operator >(double a) {
    return !((*this) <= a);
}
/* -------------------------------------------------------------------------------- */
bool logVar::operator >=(const logVar& a) {
    return !((*this) < a);

}
bool logVar::operator >=(double a) {
    return !((*this) < a);
}
/* -------------------------------------------------------------------------------- */



/* -------------------------------------------------------------------------------- */
void logVar::operator +=(const logVar& a) {
    _accumulatePositive(a._logAns);
}
void logVar::operator +=(double a) {
    if(!_checkVal(a)) {
        string message = "logVar can only handle values between 0 and 1.  a was: "+to_string(a);
        failWithMessage(__FILE__,__LINE__,message);
    }
    _accumulatePositive(_safeLog(a));
}
/* -------------------------------------------------------------------------------- */
logVar logVar::operator +(const logVar& a) {
    logVar ans;
    ans = (*this);
    ans += a;
    return ans;
}
logVar logVar::operator +(double a) {
    if(!_checkVal(a)) {
        string message = "logVar can only handle values between 0 and 1.  a was: "+to_string(a);
        failWithMessage(__FILE__,__LINE__,message);
    }
    logVar ans;
    ans = (*this);
    ans += a;
    return ans;
}
/* -------------------------------------------------------------------------------- */
void logVar::operator -=(const logVar& a) {
    _accumulateNegative(a._logAns);
}
void logVar::operator -=(double a) {
    if(!_checkVal(a)) {
        string message = "logVar can only handle values between 0 and 1.  a was: "+to_string(a);
        failWithMessage(__FILE__,__LINE__,message);
    }
    _accumulateNegative(_safeLog(a));
}
/* -------------------------------------------------------------------------------- */
logVar logVar::operator -(const logVar& a) {
    logVar ans;
    ans = (*this);
    ans -= a;
    return ans;
}
logVar logVar::operator -(double a) {
    if(!_checkVal(a)) {
        string message = "logVar can only handle values between 0 and 1.  a was: "+to_string(a);
        failWithMessage(__FILE__,__LINE__,message);
    }
    logVar ans;
    ans = (*this);
    ans -= a;
    return ans;
}
/* -------------------------------------------------------------------------------- */
void logVar::_mul(double log_x) {
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
void logVar::operator *=(const logVar& a) {
    double log_x = a._logAns;
    _mul(log_x);
}
void logVar::operator *=(double a) {
    if(a < 0) {
        string message = "logVar can only handle values between 0 and 1.  a was: "+to_string(a);
        failWithMessage(__FILE__,__LINE__,message);
    }
    double log_x = _safeLog(a,false);
    _mul(log_x);
}
/* -------------------------------------------------------------------------------- */
logVar logVar::operator *(const logVar& a) {
    logVar ans;
    ans = (*this);
    ans *= a;
    return ans;
}
logVar logVar::operator *(double a) {
    if(a < 0) {
        string message = "logVar can only handle values between 0 and 1.  a was: "+to_string(a);
        failWithMessage(__FILE__,__LINE__,message);
    }
    logVar ans;
    ans = (*this);
    ans *= a;
    return ans;
}

/* -------------------------------------------------------------------------------- */
void logVar::_div(double log_x) {
    if(log_x == UNIQUE_ZERO_ID) {
        string message = "DIVIDING BY ZERO!";
        failWithMessage(__FILE__,__LINE__,message);
    }
    if(_logAns == UNIQUE_ZERO_ID) {
        return;
    }
    if(log_x < _logAns) {
        string message = "logVar can only handle values between 0 and 1";
        failWithMessage(__FILE__,__LINE__,message);
    }
    _logAns -= log_x;
}
void logVar::operator /=(const logVar& a) {
    double log_x = a._logAns;
    _div(log_x);
}
void logVar::operator /=(double a) {
    double log_x = _safeLog(a,false);
    _div(log_x);
}
/* -------------------------------------------------------------------------------- */
logVar logVar::operator /(const logVar& a) {
    logVar ans;
    ans = (*this);
    ans /= a;
    return ans;
}
logVar logVar::operator /(double a) {
    if(a < 0) {
        string message = "logVar can only handle values between 0 and 1.  a was: "+to_string(a);
        failWithMessage(__FILE__,__LINE__,message);
    }
    logVar ans;
    ans = (*this);
    ans /= a;
    return ans;
}









ostream& operator <<(ostream& os, const logVar& lv) {  
    os << lv.val();
    return os;
}


