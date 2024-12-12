#include "UI.h"
#include "Book.h"
#include "User.h"

void UI::showMenu() {
    cout << "1. Add Book" << endl;
    cout << "2. Add User" << endl;
    cout << "3. Borrow Book" << endl;
    cout << "4. Return Book" << endl;
    cout << "5. Show Books" << endl;
    cout << "6. Show Users" << endl;
    cout << "7. Show Borrowed Books" << endl;
    cout << "8. Exit" << endl;
}

void UI::executeOption(int option, Library& library) {
    switch (option) {
    case 1: addBook(library); break;
    case 2: addUser(library); break;
    case 3: borrowBook(library); break;
    case 4: returnBook(library); break;
    case 5: showBooks(library); break;
    case 6: showUsers(library); break;
    case 7: showBorrowedBooks(library); break;
    case 8: exit(0);
    default: cout << "Invalid option!" << endl;
    }
}

void UI::addBook(Library& library) {
    int id;
    string title, author;
    cout << "Enter Book ID: ";
    cin >> id;
    cout << "Enter Book Title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter Book Author: ";
    getline(cin, author);
    library.addBook(Book(id, title, author));
}

void UI::addUser(Library& library) {
    int id;
    string name;
    cout << "Enter User ID: ";
    cin >> id;
    cout << "Enter User Name: ";
    cin.ignore();
    getline(cin, name);
    library.addUser(User(id, name));
}

void UI::borrowBook(Library& library) {
    int bookId, userId;
    cout << "Enter Book ID to borrow: ";
    cin >> bookId;
    cout << "Enter User ID: ";
    cin >> userId;
    try {
        library.borrowBook(bookId, userId);
        cout << "Book borrowed successfully!" << endl;
    }
    catch (const LibraryException& e) {
        cout << e.what() << endl;
    }
}

void UI::returnBook(Library& library) {
    int bookId, userId;
    cout << "Enter Book ID to return: ";
    cin >> bookId;
    cout << "Enter User ID: ";
    cin >> userId;
    try {
        library.returnBook(bookId, userId);
        cout << "Book returned successfully!" << endl;
    }
    catch (const LibraryException& e) {
        cout << e.what() << endl;
    }
}

void UI::showBooks(const Library& library) {
    library.showBooks();
}

void UI::showUsers(const Library& library) {
    library.showUsers();
}

void UI::showBorrowedBooks(const Library& library) {
    library.showBorrowedBooks();
}
