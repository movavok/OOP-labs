#include "mystring/string.h"

String::String() {
    length = 0;
    data = new char[1];
    data[0] = '\0';
}

String::String(const char* str) : String() {
    if (str) {
        delete[] data;
        length = countLength(str);
        data = new char[length + 1];
        copyData(str, data);
    }
}

String::String(const String& other) {
    length = other.length;
    data = new char[length + 1];
    copyData(other.data, data);
}

String::~String() { delete[] data; }

int String::getLength() { return length; }
void String::setLength(int len) { length = len; }

int String::countLength(const char* str) {
    int len = 0;
    while (str[len] != '\0') ++len;
    return len;
}

void String::copyData(const char* orig, char* copy) const {
    int index = 0;
    while (orig[index] != '\0') {
        copy[index] = orig[index];
        ++index;
    }
    copy[index] = '\0';
}

String String::operator+(const String& other) const {
    String result;
    result.length = this->length + other.length;
    delete[] result.data;
    result.data = new char[result.length + 1];

    copyData(this->data, result.data);
    copyData(other.data, result.data + this->length);

    return result;
}

bool String::operator==(const String& other) const {
    if (length != other.length) return false;
    for (int i = 0; i < length; ++i) if (data[i] != other.data[i]) return false;
    return true;
}

bool String::operator!=(const String& other) const { return !(*this == other); }

char& String::operator[](int index) {
    if (index < 0 || index >= length) return data[length];
    return data[index];
}

const char& String::operator[](int index) const {
    if (index < 0 || index >= length) return data[length];
    return data[index];
}

ostream& operator<<(ostream& out, String& str) {
    out << str.data;
    return out;
}

istream& operator>>(istream& in, String& str) {
    char buffer[1000];
    in >> buffer;

    delete[] str.data;
    str.setLength(0);
    str.setLength(str.countLength(buffer));

    str.data = new char[str.length + 1];
    str.copyData(buffer, str.data);

    return in;
}
