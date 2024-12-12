#ifndef UI_H
#define UI_H

#include "lib.h"
#include "Library.h"

class UI {
public:
    void showMenu();
    void executeOption(int option, Library& library);
    void addBook(Library& library);
    void addUser(Library& library);
    void borrowBook(Library& library);
    void returnBook(Library& library);
    void showBooks(const Library& library);
    void showUsers(const Library& library);
    void showBorrowedBooks(const Library& library);
};

#endif // UI_H
