#include <iostream>
#include <string>

using namespace std;

int main() {
    string str1{"1234"};
    cout << "str1-> " << str1 << '\n';
    cout << "-------------------\n";
    cout << "str1.length() = " << str1.length() << '\n';
    cout << "-------------------\n";
    cout << "str1.capacity() = " << str1.capacity() << '\n';
    cout << "-------------------\n";

    string str2;
    str2 = str1;
    cout << "str2-> " << str2 << '\n';
    cout << "-------------------\n";
    cout << "str2.length() = " << str2.length() << '\n';
    cout << "-------------------\n";
    cout << "str2.capacity() = " << str2.capacity() << '\n';
    cout << "-------------------\n";

    return 0;
}
