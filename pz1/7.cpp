#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    size_t cap_cur{}, cap_old{};
    int count{};

    for (int i{}; i < 100; ++i) {
        cap_cur = str.capacity();
        str.push_back('A');
        cap_old = str.capacity();
        if (cap_cur != cap_old) ++count;
    }

    std::cout << count << '\n';
    return 0;
}
