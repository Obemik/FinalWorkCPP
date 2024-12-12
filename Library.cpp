#include "Library.h"

void Library::addBook(const Book& book) {
    books.push_back(book);
}

void Library::addUser(const User& user) {
    users.push_back(user);
}

void Library::borrowBook(int bookId, int userId) {
    auto book = find_if(books.begin(), books.end(), [bookId](const Book& b) { return b.getId() == bookId; });
    if (book == books.end()) throw LibraryException("Book not found!");

    if (!book->isAvailable()) throw LibraryException("Book is already borrowed!");

    auto user = find_if(users.begin(), users.end(), [userId](const User& u) { return u.getId() == userId; });
    if (user == users.end()) throw LibraryException("User not found!");

    book->setAvailable(false);
    user->borrowBook(bookId);
}

void Library::returnBook(int bookId, int userId) {
    auto book = find_if(books.begin(), books.end(), [bookId](const Book& b) { return b.getId() == bookId; });
    if (book == books.end()) throw LibraryException("Book not found!");

    auto user = find_if(users.begin(), users.end(), [userId](const User& u) { return u.getId() == userId; });
    if (user == users.end()) throw LibraryException("User not found!");

    book->setAvailable(true);
    user->returnBook(bookId);
}

void Library::showBooks() const {
    for (const auto& book : books) {
        cout << "ID: " << book.getId() << ", Title: " << book.getTitle() << ", Author: " << book.getAuthor()
            << ", Available: " << (book.isAvailable() ? "Yes" : "No") << endl;
    }
}

void Library::showUsers() const {
    for (const auto& user : users) {
        cout << "ID: " << user.getId() << ", Name: " << user.getName() << endl;
    }
}

void Library::showBorrowedBooks() const {
    for (const auto& user : users) {
        cout << "User: " << user.getName() << ", Borrowed Books: ";
        user.showBorrowedBooks();
    }
}

void Library::saveToFile() const {
    ofstream bookFile("library_data.txt");
    for (const auto& book : books) {
        bookFile << book.getId() << " " << book.getTitle() << " " << book.getAuthor() << " " << book.isAvailable() << endl;
    }
    bookFile.close();

    ofstream userFile("users_data.txt");
    for (const auto& user : users) {
        userFile << user.getId() << " " << user.getName() << endl;
    }
    userFile.close();
}

void Library::loadFromFile() {
    ifstream bookFile("library_data.txt");
    int id;
    string title, author;
    bool available;
    while (bookFile >> id >> ws) {
        getline(bookFile, title, ',');
        getline(bookFile, author, ',');
        bookFile >> available;
        books.push_back(Book(id, title, author, available));
    }
    bookFile.close();

    ifstream userFile("users_data.txt");
    while (userFile >> id) {
        string name;
        getline(userFile, name);
        users.push_back(User(id, name));
    }
    userFile.close();
}