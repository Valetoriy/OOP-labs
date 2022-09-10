#include "COne.hpp"
#include "CTwo.hpp"

auto main() -> int {
    const char *str{"hello world"};
    COne one{str, (long)strlen(str) + 1};
    one.print();
    COne other_one;
    other_one = std::move(one);
    other_one.print();
    one.print();

    CTwo two{12.2, other_one};  // NOLINT
    two.print();
    CTwo other_two;
    other_two = two;
    other_two.print();
    two.print();

    return 0;
}
