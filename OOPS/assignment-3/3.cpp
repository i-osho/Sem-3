#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
    char *title;
    char *author;
    char *publisher;
    float price;
    int stock;
    static int successfulTransactions;
    static int failedTransactions;
    void setPrice(float tprice)
    {
        price = tprice;
    }

public:
    Book(const char *ttitle, const char *tauthor, const char *tpublisher, float tprice, int tstock)
    {
        title = new char[strlen(ttitle) + 1];
        strcpy(title, ttitle);
        author = new char[strlen(tauthor) + 1];
        strcpy(author, tauthor);
        publisher = new char[strlen(tpublisher) + 1];
        strcpy(publisher, tpublisher);
        price = tprice;
        stock = tstock;
    }

    ~Book()
    {
        delete[] title;
        delete[] author;
        delete[] publisher;
    }

    const char *Title() const
    {
        return title;
    }
    const char *Author() const
    {
        return author;
    }
    const char *Publisher() const
    {
        return publisher;
    }
    float Price()
    {
        return price;
    }
    int Stock()
    {
        return stock;
    }

    friend void search(Book B[])
    {
        char T[100], A[100];
        cout << "Enter the title of the book you want to search: ";
        cin.getline(T, 100);
        cout << "Enter the author of the book you want to search: ";
        cin.getline(A, 100);
        bool found = false;
        for (int i = 0; i < 5; i++)
        {
            if (_stricmp(B[i].Title(), T) == 0 && _stricmp(B[i].Author(), A) == 0)
            {
                cout << endl << "Book found!" << endl;
                cout << "Title: " << B[i].Title() << endl;
                cout << "Author: " << B[i].Author() << endl;
                cout << "Publisher: " << B[i].Publisher() << endl;
                cout << "Price: " << B[i].Price() << endl << endl;
                found = true;
                int choice;
                cout << "Enter 1 to request order" << endl;
                cout << "Enter 2 to update price" << endl;
                cin >> choice;
                cin.ignore();
                if (choice == 1)
                    B[i].requestOrder();
                else if (choice == 2)
                {
                    float tprice;
                    cout << "Enter the new price: ";
                    cin >> tprice;
                    B[i].setPrice(tprice);
                }
                else
                {
                    cout << "Invalid choice" << endl;
                }
                return;
            }
        }
        if (!found)
        {
            cout << "Book not found!" << endl;
        }
    }

    void requestOrder()
    {
        int n;
        cout << "Enter the number of copies you want to order: ";
        cin >> n;
        if (n <= stock)
        {
            cout << "Total Cost of " << n << " copies is " << n * price << endl;
            stock -= n;
            this->successfulTransactions++;
        }
        else
        {
            cout << "Required copies not in stock" << endl;
            this->failedTransactions++;
        }
    }
    void updatePrice(float tprice)
    {
        setPrice(tprice);
    }
    friend void showStats(Book A[])
    {
        cout << "Successful Transactions: " << A[0].successfulTransactions << endl;
        cout << "Failed Transactions: " << A[0].failedTransactions << endl;
    }

};

int Book::successfulTransactions = 0;
int Book::failedTransactions = 0;

int main()
{
    Book books[10] = {
        Book("C++ Programming", "Bjarne Stroustrup", "Pearson", 500, 10),
        Book("Data Structures", "Yashavant Kanetkar", "BPB", 400, 5),
        Book("Let Us C", "Yashavant Kanetkar", "BPB", 300, 15),
        Book("Let Us C++", "Yashavant Kanetkar", "BPB", 350, 20),
        Book("Engineering Mathematics", "B.S. Grewal", "Khanna", 600, 25),
        Book("Network Security", "William Stallings", "Pearson", 700, 30),
        Book("Computer Networks", "Andrew S. Tanenbaum", "Pearson", 800, 35),
        Book("Operating Systems", "Andrew S. Tanenbaum", "Pearson", 900, 40),
        Book("Database Management Systems", "Raghu Ramakrishnan", "McGraw Hill", 1000, 45),
        Book("Computer Organization", "Carl Hamacher", "McGraw Hill", 1100, 50)

    };
    while (true)
    {
        int choice;
        cout << endl << "Enter 1 to search for a book" << endl;
        cout << "Enter 2 to get transactions stats" << endl;
        cout << "Enter 3 to exit" << endl;
        cin >> choice;
        cin.ignore();
        if (choice == 1)
            {search(books);}
        else if (choice == 2)
            {showStats(books);}
        else if (choice == 3)
            {break;}
        else
            {cout << "Invalid choice" << endl;}
    }
    return 0;
}