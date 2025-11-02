#ifndef STRING_H
#define STRING_H

#include <iostream>

using namespace std;

class String
{
public:
    String();
    String(const char*);
    String(const String&);
    ~String();

    int getLength();
    void setLength(int);

    int countLength(const char*);
    void copyData(const char*, char*) const;

    String operator+(const String&) const;
    bool operator==(const String&) const;
    bool operator!=(const String&) const;

    char& operator[](int);
    const char& operator[](int) const;

    friend ostream& operator<<(ostream&, String&);
    friend istream& operator>>(istream&, String&);

private:
    char* data;
    int length;
};

#endif // STRING_H
