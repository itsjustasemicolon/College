
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

class Book {
private:
    string isbn;
    string title;
    vector<string> authors;
    double price;

public:
    Book(string isbn, string title, vector<string> authors, double price)
        : isbn(isbn), title(title), authors(authors), price(price) {}

    string getISBN() const {
        return isbn;
    }

    string getTitle() const {
        return title;
    }

    double getPrice() const {
        return price;
    }
};

class BookStore {
private:
    unordered_map<string, pair<Book, int>> bookInventory; // maps ISBN to a pair of Book and its count

public:
    void addBook(const Book& book, int copies) {
        string isbn = book.getISBN();
        if (bookInventory.find(isbn) != bookInventory.end()) {
            bookInventory[isbn].second += copies; // Increase the count of copies if book already exists
        } else {
            bookInventory[isbn] = make_pair(book, copies); // Add a new book to inventory
        }
    }

    vector<string> books() const {
        vector<string> uniqueISBNs;
        for (const auto& entry : bookInventory) {
            uniqueISBNs.push_back(entry.first);
        }
        return uniqueISBNs;
    }

    int noOfCopies(const string& isbn) const {
        if (bookInventory.find(isbn) != bookInventory.end()) {
            return bookInventory.at(isbn).second;
        }
        return 0; // If ISBN not found, return 0
    }

    double totalPrice() const {
        double total = 0;
        for (const auto& entry : bookInventory) {
            total += entry.second.first.getPrice() * entry.second.second; // price * number of copies
        }
        return total;
    }

    void printInventory() const {
        for (const auto& entry : bookInventory) {
            cout << "Title: " << entry.second.first.getTitle() << ", Copies: " << entry.second.second << endl;
        }
    }
};

int main() {
    Book book1("123456", "The Great Gatsby", {"F. Scott Fitzgerald"}, 10.99);
    Book book2("234567", "1984", {"George Orwell"}, 8.99);
    Book book3("345678", "To Kill a Mockingbird", {"Harper Lee"}, 12.50);

    BookStore store;
    store.addBook(book1, 5);
    store.addBook(book2, 3);
    store.addBook(book3, 2);
    store.addBook(book1, 2); // Adding more copies of "The Great Gatsby"

    // Print the number of copies for each book along with its title
    store.printInventory();

    // Print total price of all books
    cout << "Total Price of All Books: $" << store.totalPrice() << endl;

    return 0;
}
