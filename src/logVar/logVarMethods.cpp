#include "logVar.h"

bool logVar::_checkLogVal(double log_x) {
    return log_x <= PRECISION;
}

bool logVar::_checkVal(double x) {
    return x >= 0.0 && x <= 1.0
}

bool logVar::_logEqual(double log_x, double log_y) {
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
    return diff < -LOG_PRECISION;
}

bool logVar:: _equal(double x, double y) {
    // checks to see if x and y are close enough
    if(abs(x-y) < PRECISION) {
        return true;
    }
    return false;
}

double logVar::__accumulatePositive(double log_x, double log_y) {
    // computes log(x+y) in log space
    // if x or y are basically 0, just returns the other
    if(log_x < LOG_PRECISION || log_x == UNIQUE_ZERO_ID) {
        return log_y;
    }
    if(log_y < LOG_PRECISION || log_y == UNIQUE_ZERO_ID) {
        return log_x;
    }
    if(!_checkLogVal(log_x)) {
        string message = "logVar can only handle values between 0 and 1.  log_x was: "+to_string(log_x);
        failWithMessage(__FILE__,__LINE__,message);
    }
    if(!_checkLogVal(log_y)) {
        string message = "logVar can only handle values between 0 and 1.  log_y was: "+to_string(log_y);
        failWithMessage(__FILE__,__LINE__,message);
    }
    return log_x + log1p(exp(log_y - log_x));
}

double logVar::__accumulateNegative(double log_x, double log_y) {
    // computes log(x-y) in log space
    if(!_checkLogVal(log_x)) {
        string message = "logVar can only handle values between 0 and 1.  log_x was: "+to_string(log_x);
        failWithMessage(__FILE__,__LINE__,message);
    }
    if(!_checkLogVal(log_y)) {
        string message = "logVar can only handle values between 0 and 1.  log_y was: "+to_string(log_y);
        failWithMessage(__FILE__,__LINE__,message);
    }
    if(log_y > log_x) {
        string message = "log_x was: "+to_string(log_x)+"log_y was: "+to_string(log_y);
        failWithMessage(__FILE__,__LINE__,message);
    }
    return log_x + log1p(-exp(log_y - log_x));
}

void logVar::_accumulatePositive(double log_x) {
    double lastVal = _logAns;
    _logAns = __accumulatePositive(_logAns, log_x);
}

void logVar::_accumulateNegative(double log_x) {
    double lastVal = _logAns;
    _logAns = __accumulateNegative(_logAns, log_x);
}

void logVar::_addPoint(int sign, double log_x) {
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
void logVar::_addPositiveLogPoint(double log_x) {
    _addPoint(1,log_x);
}
void logVar::_addNegativeLogPoint(double log_x) {
    _addPoint(-1,log_x);
}
void logVar::_addZeroPoint() {
    return;
}
void logVar::_addPoint(double x) {
    if(x == 0) {
        return;
    }
    _addPoint(sgn(x),log(abs(x)));
}
double _getNormalAns() {
    if(_logAns == UNIQUE_ZERO_ID) {
        return 0;
    }
    return exp(_logAns);

}

