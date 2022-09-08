#include <iostream>
#include <string>

using namespace std;

int main() {
    string str{"1234"};
    cout << "str-> " << str << '\n';
    cout << "-------------------\n";
    cout << "str.length() = " << str.length() << '\n';
    cout << "-------------------\n";
    cout << "str.capacity() = " << str.capacity() << '\n';
    cout << "-------------------\n";

    return 0;
}
