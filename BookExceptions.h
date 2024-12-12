// BookExceptions.h
#ifndef BOOKEXCEPTIONS_H
#define BOOKEXCEPTIONS_H

#include <exception>
#include <string>

class BookUnavailableException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Book is unavailable";
    }
};

class BookNotFoundException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Book not found";
    }
};

#endif // BOOKEXCEPTIONS_H
