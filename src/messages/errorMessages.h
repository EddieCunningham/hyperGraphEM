#include <iostream>

class failWithMessage {

    _abortFunction() {
        raise(SIGABRT);
    }

public:
    failWithMessage(string filename, string lineNumber, string message) {

        cout << "Failed in " << filename << " at line " << lineNumber << "\n";
        cout << message << "\n";
        cout.flush();
        _abortFunction();
    }
}