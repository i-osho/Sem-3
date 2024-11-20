#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    char *str;
    int length;

public:
    String()
    {
        length = 0;
        str = new char[1];
        str[0] = '\0';
    }

    String(const char *s)
    {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    String(const String &source)
    {
        length = source.length;
        str = new char[length + 1];
        strcpy(str, source.str);
    }

    ~String()
    {
        delete[] str;
    }

    String &operator=(const String &source)
    {
        if (this != &source)
        {
            delete[] str;
            length = source.length;
            str = new char[length + 1];
            strcpy(str, source.str);
        }
        return *this;
    }

    String operator+(const String &source) const
    {
        String temp;
        temp.length = length + source.length;
        temp.str = new char[temp.length + 2];
        strcpy(temp.str, str);
        strcat(temp.str, " ");
        strcat(temp.str, source.str);
        return temp;
    }

    operator char*()
    {
        return str;
    }

};

int main()
{
    cout << "(a) Create uninitialized string objects" << endl;
    String s1;
    cout << "Uninitialized string s1: " << s1 << endl << endl;

    cout << "(b) Create objects with string constants" << endl;
    String s2("Osho Raj");
    cout << "Initialized string s2: " << s2 << endl << endl;

    cout << "(c) Concatenate two strings properly" << endl;
    String s3("My name is");
    cout << "Initialized string s3: " << s3 << endl;
    String s4 = s3+s2;
    cout << "Concatenated string s4: " << s4 << endl << endl;

    cout << "(d) Copy one string to another" << endl;
    String s5;
    s5 = s2;
    cout << "Copied string s5 from s2: " << s5 << endl;

    return 0;
}
