#include "mystring/string.h"

int main()
{
    String s1, s2;

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    cout << "You entered:" << endl;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    String s3 = s1 + s2;
    cout << "s1 + s2 = " << s3 << endl;

    cout << "s1 == s2 is " << (s1 == s2 ? "true" : "false") << endl;
    cout << "s1 != s2 is " << (s1 != s2 ? "true" : "false") << endl;

    if (s1.getLength() > 0) {
        cout << "First character of s1: " << s1[0] << endl;

        int index;
        char newChar;
        cout << "Enter index of character to change (0 to " << s1.getLength() - 1 << "): ";
        cin >> index;
        cout << "Enter new character: ";
        cin >> newChar;

        if (index >= 0 && index < s1.getLength()) {
            s1[index] = newChar;
            cout << "s1 after modification: " << s1 << endl;
        } else {
            cout << "Invalid index!" << endl;
        }
    }
    return 0;
}
