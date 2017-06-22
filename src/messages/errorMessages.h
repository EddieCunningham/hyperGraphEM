#include <iostream>
#include <csignal>


class failWithMessage {

    void _abortFunction() {
        raise(SIGABRT);
    }

public:
    failWithMessage(std::string filename, int lineNumber, std::string message) {

        std::cout << "Failed in " << filename << " at line " << lineNumber << "\n";
        std::cout << message << "\n";
        std::cout.flush();
        _abortFunction();
    }
};
