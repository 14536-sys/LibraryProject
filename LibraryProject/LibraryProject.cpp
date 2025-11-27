#include <iostream>
#include <string>
#include <array>

using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool available;

public:
    // Constructors
    Book() : title(""), author(""), isbn(""), available(true) {}
    Book(const string& t, const string& a, const string& i, bool av = true)
        : title(t), author(a), isbn(i), available(av) {
    }

    // Set book details
    void setBookDetails(const string& t, const string& a, const string& i, bool av = true) {
        title = t;
        author = a;
        isbn = i;
        available = av;
    }

    // Display details
    void displayBookDetails() const {
        cout << "Title: " << title << "\n";
        cout << "Author: " << author << "\n";
        cout << "ISBN: " << isbn << "\n";
        cout << "Availability: " << (available ? "Available" : "Borrowed") << "\n";
    }

    // Borrow the book (returns true if success)
    bool borrowBook() {
        if (available) {
            available = false;
            return true;
        }
        else {
            return false;
        }
    }

    // Return the book
    void returnBook() {
        available = true;
    }

    // Accessor for ISBN and availability
    string getISBN() const { return isbn; }
    bool isAvailable() const { return available; }
};

int main() {
    // Initialize 5 books
    array<Book, 5> books;
    books[0].setBookDetails("The Hobbit", "J.R.R. Tolkien", "9780261102217", true);
    books[1].setBookDetails("1984", "George Orwell", "9780451524935", true);
    books[2].setBookDetails("To Kill a Mockingbird", "Harper Lee", "9780061120084", true);
    books[3].setBookDetails("Pride and Prejudice", "Jane Austen", "9780141439518", true);
    books[4].setBookDetails("Clean Code", "Robert C. Martin", "9780132350884", true);

    cout << "Simple Library System\n";
    cout << "Enter an ISBN to borrow the book, or enter 0 to exit.\n\n";

    while (true) {
        // Display available books summary
        cout << "Current books in library:\n";
        for (const auto& b : books) {
            cout << "- " << b.getISBN() << " : "
                << (b.isAvailable() ? "Available" : "Borrowed") << "\n";
        }
        cout << "\n";

        cout << "Enter ISBN (or 0 to quit): ";
        string input;
        getline(cin, input);

        if (input == "0") {
            cout << "Exiting program. Goodbye.\n";
            break;
        }

        bool found = false;
        for (auto& b : books) {
            if (b.getISBN() == input) {
                found = true;
                if (b.isAvailable()) {
                    b.borrowBook();
                    cout << "Success: You have borrowed the book.\n";
                    cout << "Book details:\n";
                    b.displayBookDetails();
                }
                else {
                    cout << "Sorry, this book is currently borrowed by someone else.\n";
                }
                break;
            }
        }

        if (!found) {
            cout << "No book found with ISBN: " << input << "\n";
        }

        cout << "\n"; // spacing before next loop
    }

    return 0;
}
