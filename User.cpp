#include "User.h"

User::User(int id, const string& name) : id(id), name(name) {}

int User::getId() const {
    return id;
}

string User::getName() const {
    return name;
}

void User::borrowBook(int bookId) {
    borrowedBooks.push_back(bookId);
}

void User::returnBook(int bookId) {
    auto it = find(borrowedBooks.begin(), borrowedBooks.end(), bookId);
    if (it != borrowedBooks.end()) {
        borrowedBooks.erase(it);
    }
}

void User::showBorrowedBooks() const {
    for (const auto& bookId : borrowedBooks) {
        cout << "Book ID: " << bookId << endl;
    }
}
