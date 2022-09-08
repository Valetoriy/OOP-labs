#include <iostream>
#include <string>

using namespace std;

int main() {
    string str1{"1234"};
    string str2{"5678"};
    str2 += str1;
    // str2.append(str1);
    cout << "str2-> " << str2 << '\n';
    cout << "-------------------\n";
    cout << "str2.length() = " << str2.length() << '\n';
    cout << "-------------------\n";
    cout << "str2.capacity() = " << str2.capacity() << '\n';
    cout << "-------------------\n";

    return 0;
}
