#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "lib.h"

class LibraryException : public exception {
public:
    explicit LibraryException(const string& message) : message(message) {}
    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    string message;
};

#endif // EXCEPTION_H
