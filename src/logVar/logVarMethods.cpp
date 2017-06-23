#include "/Users/Eddie/hyperGraphEM/src/logVar/logVar.h"


double LogVar::_safeLog(double x, bool checkVal) {
    if(checkVal && !_checkVal(x)) {
        string message = "LogVar can only handle values between 0 and 1.  x was: "+to_string(x);
        failWithMessage(__FILE__,__LINE__,message);
    }
    if(_equal(x,0.0)) {
        return UNIQUE_ZERO_ID;
    }
    return log(x);
}

bool LogVar::_checkLogVal(double log_x) {
    return log_x < PRECISION || log_x == UNIQUE_ZERO_ID;
}

bool LogVar::_checkVal(double x) {
    return x > 0.0 - PRECISION && x < 1.0 + PRECISION;
}

bool LogVar::_logEqual(double log_x, double log_y) {
    // checks to see that x and y are sufficiently close in log space
    if(log_x == UNIQUE_ZERO_ID) {
        if(log_y == UNIQUE_ZERO_ID) {
            return true;
        }
        return false;
    }
    if(log_y == UNIQUE_ZERO_ID) {
        return false;
    }
    double diff;
    if(log_x > log_y) {
        diff = log_x + log1p(-exp(log_y - log_x));
    }
    else {
        diff = log_y + log1p(-exp(log_x - log_y));
    }
    return diff < LOG_PRECISION;
}

bool LogVar:: _equal(double x, double y) {
    // checks to see if x and y are close enough
    if(abs(x-y) < PRECISION) {
        return true;
    }
    return false;
}

double LogVar::__accumulatePositive(double log_x, double log_y) {
    // computes log(x+y) in log space
    // if x or y are basically 0, just returns the other
    if(log_x < LOG_PRECISION || log_x == UNIQUE_ZERO_ID) {
        return log_y;
    }
    if(log_y < LOG_PRECISION || log_y == UNIQUE_ZERO_ID) {
        return log_x;
    }
    if(!_checkLogVal(log_x)) {
        string message = "LogVar can only handle values between 0 and 1.  log_x was: "+to_string(log_x);
        failWithMessage(__FILE__,__LINE__,message);
    }
    if(!_checkLogVal(log_y)) {
        string message = "LogVar can only handle values between 0 and 1.  log_y was: "+to_string(log_y);
        failWithMessage(__FILE__,__LINE__,message);
    }
    double ans = log_x + log1p(exp(log_y - log_x));
    
    if(!_checkLogVal(ans)) {
        string message = "LogVar can only handle values between 0 and 1.  ans was: "+to_string(ans);
        failWithMessage(__FILE__,__LINE__,message);
    }
    
    if(ans < LOG_PRECISION) {
        return UNIQUE_ZERO_ID;
    }
    return log_x + log1p(exp(log_y - log_x));
}

double LogVar::__accumulateNegative(double log_x, double log_y) {
    // computes log(x-y) in log space
    if(log_y < LOG_PRECISION || log_y == UNIQUE_ZERO_ID) {
        return log_x;
    }
    if(!_checkLogVal(log_x)) {
        string message = "LogVar can only handle values between 0 and 1.  log_x was: "+to_string(log_x);
        failWithMessage(__FILE__,__LINE__,message);
    }
    if(!_checkLogVal(log_y)) {
        string message = "LogVar can only handle values between 0 and 1.  log_y was: "+to_string(log_y);
        failWithMessage(__FILE__,__LINE__,message);
    }
    if(log_x == UNIQUE_ZERO_ID && log_y != UNIQUE_ZERO_ID) {
        string message = "log_x was: "+to_string(log_x)+" log_y was: "+to_string(log_y);
        failWithMessage(__FILE__,__LINE__,message);
    }
    if(log_y > log_x) {
        string message = "log_x was: "+to_string(log_x)+" log_y was: "+to_string(log_y);
        failWithMessage(__FILE__,__LINE__,message);
    }
    double ans = log_x + log1p(-exp(log_y - log_x));
    
    if(!_checkLogVal(ans)) {
        string message = "LogVar can only handle values between 0 and 1.  ans was: "+to_string(ans);
        failWithMessage(__FILE__,__LINE__,message);
    }
    
    if(ans < LOG_PRECISION) {
        return UNIQUE_ZERO_ID;
    }
    return log_x + log1p(-exp(log_y - log_x));
}

void LogVar::_accumulatePositive(double log_x) {
    _logAns = __accumulatePositive(_logAns, log_x);
}

void LogVar::_accumulateNegative(double log_x) {
    _logAns = __accumulateNegative(_logAns, log_x);
}

void LogVar::_addPoint(int sign, double log_x) {
    if(sign == 0) {
        return;
    }
    else if(_logAns == UNIQUE_ZERO_ID) {
        _logAns = log_x;
    }
    else if(sign == -1) {
        _accumulateNegative(log_x);
    }
    else if(sign == 1){
        _accumulatePositive(log_x);
    }
    else {
        return;
    }
}
void LogVar::_addPositiveLogPoint(double log_x) {
    _addPoint(1,log_x);
}
void LogVar::_addNegativeLogPoint(double log_x) {
    _addPoint(-1,log_x);
}
void LogVar::_addZeroPoint() {
    return;
}
int sgn(double val) {
    if(val == 0) {
        return 0;
    }
    else if(val < 0) {
        return -1;
    }
    else {
        return 1;
    }
}
void LogVar::_addPoint(double x) {
    if(x == 0) {
        return;
    }
    _addPoint(sgn(x),log(abs(x)));
}
double LogVar::val() const {
    if(_logAns == UNIQUE_ZERO_ID) {
        return 0;
    }
    return exp(_logAns);

}

