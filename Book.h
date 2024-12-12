#ifndef BOOK_H
#define BOOK_H

#include "lib.h"

class Book {
public:
    Book(int id, const string& title, const string& author, bool isAvailable = true);
    int getId() const;
    string getTitle() const;
    string getAuthor() const;
    bool isAvailable() const;
    void setAvailable(bool available);

private:
    int id;
    string title;
    string author;
    bool available;
};

#endif // BOOK_H
