#include <iostream>
#include <string>

using namespace std;

int main() {
    string str{"012345"};
    string sub{str.substr(1, 3)};
    cout << "sub-> " << sub << '\n';
    cout << "-------------------\n";
    cout << "sub.length() = " << sub.length() << '\n';
    cout << "-------------------\n";
    cout << "sub.capacity() = " << sub.capacity() << '\n';
    cout << "-------------------\n";

    return 0;
}
