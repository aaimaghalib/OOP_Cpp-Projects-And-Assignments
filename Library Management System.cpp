#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

// Base Class
class LibraryItem
{
public:
    string name;
    LibraryItem(string n = "") : name(n) {}
};

// Book Class
class Book : public LibraryItem
{
public:
    string author;
    string genre;
    bool available;

    Book() : LibraryItem(""), author(""), genre(""), available(true) {}

    Book(string title, string a, string g)
        : LibraryItem(title), author(a), genre(g), available(true) {}
};

// Patron Class
class Patron : public LibraryItem
{
public:
    string contact;
    vector<string> borrowedBooks;   // Multiple books

    Patron(string n = "", string c = "") : LibraryItem(n), contact(c) {}
};

// Library Class
class Library
{
private:
    static const int MAX_BOOKS = 100;
    static const int MAX_PATRONS = 100;

    vector<Book> books;
    vector<Patron> patrons;

public:

    // Add Book
    void addBook()
    {
        if (books.size() >= MAX_BOOKS)
        {
            cout << "Library book limit reached.\n";
            return;
        }

        string title, author, genre;

        cout << "Enter book title: ";
        getline(cin, title);

        if (title.empty())
        {
            cout << "Title cannot be empty.\n";
            return;
        }

        auto duplicate = find_if(books.begin(), books.end(),
            [&](const Book& b) { return b.name == title; });

        if (duplicate != books.end())
        {
            cout << "Book already exists.\n";
            return;
        }

        cout << "Enter author: ";
        getline(cin, author);

        cout << "Enter genre: ";
        getline(cin, genre);

        books.push_back(Book(title, author, genre));
        cout << "Book added successfully.\n";
    }

    // Remove Book
    void removeBook()
    {
        string title;
        cout << "Enter book title to remove: ";
        getline(cin, title);

        auto it = find_if(books.begin(), books.end(),
            [&](const Book& b) { return b.name == title; });

        if (it == books.end())
        {
            cout << "Book not found.\n";
            return;
        }

        if (!it->available)
        {
            cout << "Cannot remove. Book is issued.\n";
            return;
        }

        books.erase(it);
        cout << "Book removed successfully.\n";
    }

    // Register Patron
    void registerPatron()
    {
        if (patrons.size() >= MAX_PATRONS)
        {
            cout << "Patron limit reached.\n";
            return;
        }

        string name, contact;

        cout << "Enter patron name: ";
        getline(cin, name);

        auto duplicate = find_if(patrons.begin(), patrons.end(),
            [&](const Patron& p) { return p.name == name; });

        if (duplicate != patrons.end())
        {
            cout << "Patron already registered.\n";
            return;
        }

        cout << "Enter contact: ";
        getline(cin, contact);

        patrons.push_back(Patron(name, contact));

        cout << "Patron registered successfully.\n";
    }

    // Borrow Book
    void borrowBook()
    {
        string patronName, bookTitle;

        cout << "Enter patron name: ";
        getline(cin, patronName);

        auto patronIt = find_if(patrons.begin(), patrons.end(),
            [&](const Patron& p) { return p.name == patronName; });

        if (patronIt == patrons.end())
        {
            cout << "Patron not found.\n";
            return;
        }

        cout << "Enter book title: ";
        getline(cin, bookTitle);

        auto bookIt = find_if(books.begin(), books.end(),
            [&](const Book& b) { return b.name == bookTitle; });

        if (bookIt == books.end())
        {
            cout << "Book not found.\n";
            return;
        }

        if (!bookIt->available)
        {
            cout << "Book already issued.\n";
            return;
        }

        bookIt->available = false;
        patronIt->borrowedBooks.push_back(bookTitle);

        cout << "Book borrowed successfully.\n";
    }

    // Return Book
    void returnBook()
    {
        string patronName, bookTitle;

        cout << "Enter patron name: ";
        getline(cin, patronName);

        auto patronIt = find_if(patrons.begin(), patrons.end(),
            [&](const Patron& p) { return p.name == patronName; });

        if (patronIt == patrons.end())
        {
            cout << "Patron not found.\n";
            return;
        }

        cout << "Enter book title to return: ";
        getline(cin, bookTitle);

        auto borrowedIt = find(patronIt->borrowedBooks.begin(),
                               patronIt->borrowedBooks.end(),
                               bookTitle);

        if (borrowedIt == patronIt->borrowedBooks.end())
        {
            cout << "This patron did not borrow this book.\n";
            return;
        }

        auto bookIt = find_if(books.begin(), books.end(),
            [&](const Book& b) { return b.name == bookTitle; });

        if (bookIt != books.end())
        {
            bookIt->available = true;
        }

        patronIt->borrowedBooks.erase(borrowedIt);

        cout << "Book returned successfully.\n";
    }

    // Display Books
    void displayBooks()
    {
        cout << "\nBooks in Library\n";

        for (const auto& book : books)
        {
            cout << "Title: " << setw(20) << left << book.name
                 << "Author: " << setw(20) << left << book.author
                 << "Genre: " << setw(15) << left << book.genre
                 << "Available: " << (book.available ? "Yes" : "No")
                 << endl;
        }

        cout << endl;
    }

    // Display Patrons
    void displayPatrons()
    {
        cout << "\nPatrons\n";

        for (const auto& patron : patrons)
        {
            cout << "Name: " << setw(20) << left << patron.name
                 << "Contact: " << setw(20) << left << patron.contact;

            if (patron.borrowedBooks.empty())
            {
                cout << "Borrowed Books: None";
            }
            else
            {
                cout << "Borrowed Books: ";
                for (auto b : patron.borrowedBooks)
                    cout << b << " ";
            }

            cout << endl;
        }

        cout << endl;
    }

    // Search Book
    void searchBook()
    {
        string title;
        cout << "Enter book title: ";
        getline(cin, title);

        auto it = find_if(books.begin(), books.end(),
            [&](const Book& b) { return b.name == title; });

        if (it == books.end())
        {
            cout << "Book not found.\n";
            return;
        }

        cout << "\nBook Found\n";
        cout << "Title: " << it->name << endl;
        cout << "Author: " << it->author << endl;
        cout << "Genre: " << it->genre << endl;
        cout << "Available: " << (it->available ? "Yes" : "No") << endl;
    }

    // View Issued Books
    void viewIssuedBooks()
    {
        cout << "\nIssued Books\n";

        for (const auto& patron : patrons)
        {
            for (auto book : patron.borrowedBooks)
            {
                cout << "Patron: " << setw(20) << left << patron.name
                     << "Book: " << book << endl;
            }
        }

        cout << endl;
    }

    // Modify Patron
    void modifyPatronRecord()
    {
        string name, newContact;

        cout << "Enter patron name: ";
        getline(cin, name);

        auto it = find_if(patrons.begin(), patrons.end(),
            [&](const Patron& p) { return p.name == name; });

        if (it == patrons.end())
        {
            cout << "Patron not found.\n";
            return;
        }

        cout << "Enter new contact: ";
        getline(cin, newContact);

        it->contact = newContact;

        cout << "Record updated.\n";
    }

    // Delete Patron
    void deletePatronRecord()
    {
        string name;

        cout << "Enter patron name: ";
        getline(cin, name);

        auto it = find_if(patrons.begin(), patrons.end(),
            [&](const Patron& p) { return p.name == name; });

        if (it == patrons.end())
        {
            cout << "Patron not found.\n";
            return;
        }

        if (!it->borrowedBooks.empty())
        {
            cout << "Cannot delete. Patron has borrowed books.\n";
            return;
        }

        patrons.erase(it);

        cout << "Patron deleted successfully.\n";
    }
};

// Main Function
int main()
{
    Library library;
    int choice;

    while (true)
    {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Register Patron\n";
        cout << "4. Borrow Book\n";
        cout << "5. Return Book\n";
        cout << "6. Display Books\n";
        cout << "7. Display Patrons\n";
        cout << "8. Search Book\n";
        cout << "9. View Issued Books\n";
        cout << "10. Modify Patron Record\n";
        cout << "11. Delete Patron Record\n";
        cout << "12. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1: library.addBook(); break;
        case 2: library.removeBook(); break;
        case 3: library.registerPatron(); break;
        case 4: library.borrowBook(); break;
        case 5: library.returnBook(); break;
        case 6: library.displayBooks(); break;
        case 7: library.displayPatrons(); break;
        case 8: library.searchBook(); break;
        case 9: library.viewIssuedBooks(); break;
        case 10: library.modifyPatronRecord(); break;
        case 11: library.deletePatronRecord(); break;
        case 12:
            cout << "Goodbye.\n";
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }
}
