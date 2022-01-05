#include <iostream>
using namespace std;

class Book
{
public:
    string title, author, publisher;
    int year, pages, price;
    Book(string t, string a, string p, int y, int pgs, int pr)
    {
        title = t;
        author = a;
        publisher = p;
        year = y;
        pages = pgs;
        price = pr;
    }
};

int main()
{

    Book myBook("The Art of Computer Programming", "Donald Knuth", "Addison-Wesley", 1968, 672, 599);
    Book myBook2("The C++ Programming Language", "Bjarne Stroustrup", "Addison-Wesley", 2011, 792, 599);
    cout << myBook.title << endl;
    cout << myBook2.title << endl;
    return 0;
}