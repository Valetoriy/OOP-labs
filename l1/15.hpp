#ifndef TASK_15_HPP
#define TASK_15_HPP

#include <concepts>
#include <iostream>

template <std::floating_point Contained>
struct Complex {
    auto print() const noexcept -> void {
        std::cout << "real: " << real << ", "
                  << "imag: " << imag << '\n';
    }
    [[nodiscard]] constexpr auto operator+(const Complex &other) const noexcept
        -> Complex {
        return {real + other.real, imag + other.imag};
    }

    [[nodiscard]] constexpr auto operator-(const Complex &other) const noexcept
        -> Complex {
        return {real - other.real, imag - other.imag};
    }

    [[nodiscard]] constexpr auto operator*(const Complex &other) const noexcept
        -> Complex {
        return {real * other.real - imag * other.imag,
                imag * other.real + real * other.imag};
    }

    [[nodiscard]] constexpr auto operator/(const Complex &other) const noexcept
        -> Complex {
        Contained denom{other.real * other.real + other.imag * other.imag};

        Contained temp_r{(real * other.real + imag * other.imag) / denom};
        Contained temp_i{(imag * other.real - real * other.imag) / denom};

        return {temp_r, temp_i};
    }

    Contained real;
    Contained imag;
};

#endif
