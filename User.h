#ifndef USER_H
#define USER_H

#include "lib.h"
#include "Book.h"
#include "Exception.h"

class User {
public:
    User(int id, const string& name);
    int getId() const;
    string getName() const;
    void borrowBook(int bookId);
    void returnBook(int bookId);
    void showBorrowedBooks() const;

private:
    int id;
    string name;
    vector<int> borrowedBooks;
};

#endif // USER_H
