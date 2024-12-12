#ifndef LIBRARY_H
#define LIBRARY_H

#include "lib.h"
#include "Book.h"
#include "User.h"
#include "Exception.h"

class Library {
public:
    void addBook(const Book& book);
    void addUser(const User& user);
    void borrowBook(int bookId, int userId);
    void returnBook(int bookId, int userId);
    void showBooks() const;
    void showUsers() const;
    void showBorrowedBooks() const;
    void saveToFile() const;
    void loadFromFile();

private:
    vector<Book> books;
    vector<User> users;
};

#endif // LIBRARY_H
