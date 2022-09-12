#include "15.hpp"
#include "9.hpp"

auto example9() noexcept -> void {
    DynamicArray<int> arr{5};  // NOLINT
    try {
        arr.at(5) = 12;  // NOLINT
    } catch (const std::exception &exc) {
        std::cout << "Поймано исключение: " << exc.what() << '\n';
    }

    puts("arr input_elems():");
    arr.input_elems();

    arr.push_back(12);  // NOLINT
    puts("arr push_back():");
    arr.print_elems();

    auto arr2{arr};
    puts("arr2 = arr:");
    arr2.print_elems();

    arr2.insert(2, arr);
    puts("arr2 insert:");
    arr2.print_elems();

    puts("arr2 max_elem():");
    std::cout << arr2.max_elem() << '\n';
}

auto example15() noexcept -> void {
    Complex<float> com{1, 2};
    Complex<float> com2{com + Complex<float>{2, 2}};

    puts("(1 + 2i) + (3 + 4i):");
    auto com3{com + com2};
    com3.print();

    puts("(1 + 2i) - (3 + 4i):");
    com3 = com - com2;
    com3.print();

    puts("(1 + 2i) * (3 + 4i):");
    com3 = com * com2;
    com3.print();

    puts("(1 + 2i) / (3 + 4i):");
    com3 = com / com2;
    com3.print();
}

auto main() -> int {
    example9();
    // example15();

    return 0;
}
