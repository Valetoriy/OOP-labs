#include "CFour.hpp"

auto printAll(CTwo **arr, const int size) -> void {
    for (int ind{}; ind < size; ++ind) {
        arr[ind]->print();
        puts("---");
    }
}

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

    puts("---CFour---");
    CFour four{other_three, true};
    four.print();
    CFour other_four{four};
    other_four.print();
    four.print();

    puts("---printAll()---");
    CTwo *arr[]{&other_two, &other_three, &other_four};
    printAll(arr, sizeof(arr) / sizeof(void *));

    return 0;
}
