#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    size_t cap_cur{}, cap_old{};

    for (int i{}; i < 100; ++i) {
        cap_cur = str.capacity();
        str.push_back('A');
        cap_old = str.capacity();
        if (cap_cur != cap_old)
            std::cout << i << ' ' << cap_cur << ' ' << cap_old << '\n';
    }
    return 0;
}
