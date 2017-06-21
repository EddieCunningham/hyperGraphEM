#include "logVar.h"

void logVar::operator =(const logVar& a) {
    _logAns = a._logAns;
}
void logVar::operator =(double a) {
    if(!_checkVal(a)) {
        string message = "logVar can only handle values between 0 and 1.  a was: "+to_string(a);
        failWithMessage(__FILE__,__LINE__,message);
    }
    if(_equal(a,0)) {
        _logAns = UNIQUE_ZERO_ID;
    }
    _logAns = log(a);
}




bool logVar::operator <(const logVar& a) {
    if(a._logAns == UNIQUE_ZERO_ID) {
        return false;
    }
    return _logAns < a._logAns;
}
bool logVar::operator <(double a) {
    if(a >= 1.0) {
        return true;
    }
    else if(a <= 0.0) {
        return false;
    }
    return _logAns < log(a);
}





bool logVar::operator <=(const logVar& a) {
    return _logAns < a._logAns || _logEqual(_logAns,a._logAns);
}
bool logVar::operator <=(double a) {
    if(a > 1.0) {
        return true;
    }
    else if(_equal(a,1.0)) {
        return _logEqual(_logAns,0.0);
    }
    else if(a < 0.0) {
        return false;
    }
    else if(_equal(a,0.0)) {
        return _logAns == UNIQUE_ZERO_ID;
    }
    return _logAns < log(a);
}





bool logVar::operator >(const logVar& a) {
    // if(_logAns == UNIQUE_ZERO_ID) {
    //     return false;
    // }
    // return _logAns > a._logAns;
    return !((*this) < a);
}
bool logVar::operator >(double a) {
    // if(a >= 1.0) {
    //     return false;
    // }
    // else if(a <= 0.0) {
    //     return true;
    // }
    // return _logAns > log(a);
    return !((*this) < a);
}





bool logVar::operator >=(const logVar& a) {
    return _logAns > a._logAns || _logEqual(_logAns,a._logAns);

}
bool logVar::operator >=(double a) {
    if(a > 1.0) {
        return false;
    }
    else if(_equal(a,1.0)) {
        return _logEqual(_logAns,0.0);
    }
    else if(a < 0.0) {
        return true;
    }
    else if(_equal(a,0.0)) {
        return _logAns == UNIQUE_ZERO_ID;
    }
    return _logAns > log(a);
}




bool logVar::operator ==(const logVar& a) {
    return _logEqual(_logAns,a._logAns);

}
bool logVar::operator ==(double a) {
    if(!_checkVal(a)) {
        return false;
    }
    return _logEqual(log(a),_logAns);
}





bool logVar::operator !=(const logVar& a) {
    return !((*this) == a)

}
bool logVar::operator !=(double a) {
    return !((*this) == a)
}





logVar logVar::operator +(const logVar& a) {
    double log_ans = __accumulatePositive(_logAns,a._logAns);
    logVar ans;
    ans._logAns = log_ans;
    return ans;
}
logVar logVar::operator +(double a) {
    if(!_checkVal(a)) {
        string message = "logVar can only handle values between 0 and 1.  a was: "+to_string(a);
        failWithMessage(__FILE__,__LINE__,message);
    }
    double log_ans = __accumulatePositive(_logAns,log(a));
    logVar ans;
    ans._logAns = log_ans;
    return ans;
}




void logVar::operator +=(const logVar& a) {
    _accumulatePositive(a._logAns);
}
void logVar::operator +=(double a) {
    if(!_checkVal(a)) {
        string message = "logVar can only handle values between 0 and 1.  a was: "+to_string(a);
        failWithMessage(__FILE__,__LINE__,message);
    }
    _accumulatePositive(log(a));
}





logVar logVar::operator -(const logVar& a) {
    double log_ans = __accumulateNegative(_logAns,a._logAns);
    logVar ans;
    ans._logAns = log_ans;
    return ans;
}
logVar logVar::operator -(double a) {
    if(!_checkVal(a)) {
        string message = "logVar can only handle values between 0 and 1.  a was: "+to_string(a);
        failWithMessage(__FILE__,__LINE__,message);
    }
    double log_ans = __accumulateNegative(_logAns,log(a));
    logVar ans;
    ans._logAns = log_ans;
    return ans;
}




logVar logVar::operator -=(const logVar& a) {
    _accumulateNegative(a._logAns);
}
logVar logVar::operator -=(double a) {
    if(!_checkVal(a)) {
        string message = "logVar can only handle values between 0 and 1.  a was: "+to_string(a);
        failWithMessage(__FILE__,__LINE__,message);
    }
    _accumulateNegative(log(a));
}






logVar logVar::operator *(const logVar& a) {
    logVar ans;
    if(_logAns == UNIQUE_ZERO_ID || a._logAns == UNIQUE_ZERO_ID) {
        return ans;
    }
    double log_ans = _logAns + a._logAns;
    ans._logAns = log_ans;
    return ans;
}
logVar logVar::operator *(double a) {
    logVar ans;
    if(_logAns == UNIQUE_ZERO_ID || _equal(a,0.0)) {
        return;
    }
    if(a < 0) {
        string message = "logVar can only handle values between 0 and 1.  a was: "+to_string(a);
        failWithMessage(__FILE__,__LINE__,message);
    }
    double log_ans = _logAns + log(a);
    ans._logAns = log_ans;
    return ans;
}






void logVar::operator *=(const logVar& a) {
    if(_logAns == UNIQUE_ZERO_ID) {
        return;
    }
    if(a._logAns == UNIQUE_ZERO_ID) {
        _logAns = UNIQUE_ZERO_ID;
    }
    _logAns += a._logAns;
}
void logVar::operator *=(double a) {
    if(_logAns == UNIQUE_ZERO_ID) {
        return;
    }
    if(a < 0) {
        string message = "logVar can only handle values between 0 and 1.  a was: "+to_string(a);
        failWithMessage(__FILE__,__LINE__,message);
    }
    if(_equal(a,0.0)) {
        _logAns = UNIQUE_ZERO_ID;
    }
    else {
        _logAns += log(a);
    }
}







logVar logVar::operator /(const logVar& a) {
    if(a._logAns == UNIQUE_ZERO_ID) {
        string message = "DIVIDING BY ZERO!";
        failWithMessage(__FILE__,__LINE__,message);
    }
    logVar ans;
    if(_logAns == UNIQUE_ZERO_ID) {
        return ans;
    }
    double log_ans = _logAns - a._logAns;
    ans._logAns = log_ans;
    return ans;
}
logVar logVar::operator /(double a) {
    if(_equal(a,0.0)) {
        string message = "DIVIDING BY ZERO!";
        failWithMessage(__FILE__,__LINE__,message);
    }
    logVar ans;
    if(_logAns == UNIQUE_ZERO_ID) {
        return;
    }
    if(a < 0) {
        string message = "logVar can only handle values between 0 and 1.  a was: "+to_string(a);
        failWithMessage(__FILE__,__LINE__,message);
    }
    double log_ans = _logAns - log(a);
    ans._logAns = log_ans;
    return ans;
}






void logVar::operator /=(const logVar& a) {
    if(a._logAns == UNIQUE_ZERO_ID) {
        string message = "DIVIDING BY ZERO!";
        failWithMessage(__FILE__,__LINE__,message);
    }
    if(_logAns == UNIQUE_ZERO_ID) {
        return;
    }
    _logAns -= a._logAns;
}
void logVar::operator /=(double a) {
    if(_equal(a,0.0)) {
        string message = "DIVIDING BY ZERO!";
        failWithMessage(__FILE__,__LINE__,message);
    }

    if(_logAns == UNIQUE_ZERO_ID) {
        return;
    }
    if(a < 0) {
        string message = "logVar can only handle values between 0 and 1.  a was: "+to_string(a);
        failWithMessage(__FILE__,__LINE__,message);
    }
    else {
        _logAns -= log(a);
    }
}



