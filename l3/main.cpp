#include "CThree.hpp"

auto main() -> int {
    puts("---COne---");
    const char *str{"hello world"};
    COne one{str, (long)strlen(str) + 1};
    one.print();
    COne other_one;
    other_one = std::move(one);
    other_one.print();
    one.print();

    puts("---CTwo---");
    CTwo two{12.2, other_one};  // NOLINT
    two.print();
    CTwo other_two;
    other_two = two;
    other_two.print();
    two.print();

    puts("---CThree---");
    CThree three{other_two, 22};  // NOLINT
    three.print();
    CThree other_three{std::move(three)};
    other_three.print();
    three.print();

    return 0;
}
