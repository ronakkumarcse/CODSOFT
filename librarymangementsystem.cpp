#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    string isbn;
    bool isAvailable;
    time_t issuedDate; 
};

vector<Book> library;

void showMenu() {
    cout << "\n==== LIBRARY MANAGEMENT SYSTEM =====\n";
    cout << "1. Add Book\n";
    cout << "2. View All Books\n";
    cout << "3. Search Book\n";
    cout << "4. Checkout Book\n";
    cout << "5. Return Book\n";
    cout << "6. Exit\n";
    cout << "Choose an option: ";
}

void addBook() {
    Book b;
    cout << "Enter Book ID: ";
    cin >> b.id;
    cin.ignore();
    cout << "Enter Title: ";
    getline(cin, b.title);
    cout << "Enter Author: ";
    getline(cin, b.author);
    cout << "Enter ISBN: ";
    getline(cin, b.isbn);
    b.isAvailable = true;
    b.issuedDate = 0;
    library.push_back(b);
    cout << "✅ Book added successfully!\n";
}

void viewBooks() {
    if (library.empty()) {
        cout << "No books in library.\n";
        return;
    }
    cout << "\nID\tTitle\t\tAuthor\t\tISBN\t\tStatus\n";
    cout << "---------------------------------------------------\n";
    for (auto &b : library) {
        cout << b.id << "\t" << b.title << "\t" << b.author << "\t" << b.isbn
             << "\t" << (b.isAvailable ? "Available" : "Issued") << endl;
    }
}

void searchBook() {
    string keyword;
    cout << "Enter title/author/ISBN to search: ";
    cin.ignore();
    getline(cin, keyword);

    bool found = false;
    for (auto &b : library) {
        if (b.title.find(keyword) != string::npos ||
            b.author.find(keyword) != string::npos ||
            b.isbn.find(keyword) != string::npos) {
            cout << "Found: " << b.title << " by " << b.author
                 << " (" << (b.isAvailable ? "Available" : "Issued") << ")\n";
            found = true;
        }
    }
    if (!found) cout << "No matching book found.\n";
}

void checkoutBook() {
    int id;
    cout << "Enter Book ID to checkout: ";
    cin >> id;

    for (auto &b : library) {
        if (b.id == id && b.isAvailable) {
            b.isAvailable = false;
            b.issuedDate = time(0);
            cout << " Book '" << b.title << "' checked out successfully!\n";
            return;
        }
    }
    cout << " Book not found or already issued.\n";
}

void returnBook() {
    int id;
    cout << "Enter Book ID to return: ";
    cin >> id;

    for (auto &b : library) {
        if (b.id == id && !b.isAvailable) {
            b.isAvailable = true;
            time_t returnTime = time(0);
            double seconds = difftime(returnTime, b.issuedDate);
            int days = seconds / (60 * 60 * 24);

            if (days > 7) { 
                int fine = (days - 7) * 5; 
                cout << " Returned after " << days
                     << " days. Fine = ₹" << fine << endl;
            } else {
                cout << " Returned on time. No fine.\n";
            }

            b.issuedDate = 0;
            return;
        }
    }
    cout << "Book not found or was not issued.\n";
}

int main() {
    int choice;
    while (true) {
        showMenu();
        cin >> choice;
        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBook(); break;
            case 4: checkoutBook(); break;
            case 5: returnBook(); break;
            case 6: cout << "👋 Exiting Library System. Goodbye!\n"; return 0;
            default: cout << "Invalid choice! Try again.\n";
        }
    }
}