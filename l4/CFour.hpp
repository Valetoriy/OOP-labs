#ifndef CFOUR_HPP
#define CFOUR_HPP

#include "CThree.hpp"

struct CFour : public CThree {
    auto print() const noexcept -> void override {
        if (m_b)
            std::cout << "b: true\n";
        else
            std::cout << "b: false\n";
        CThree::print();
    }

    [[nodiscard]] constexpr auto b() const noexcept { return m_b; }

    constexpr CFour() noexcept = default;
    constexpr CFour(const CThree &three, const bool b) noexcept  // NOLINT
        : CThree{three}, m_b{b} {}

    // Правило 5
    constexpr CFour(const CFour &other) noexcept = default;
    constexpr CFour(CFour &&other) noexcept
        : CThree{std::move(other)}, m_b{other.m_b} {
        other.m_b = false;
    }
    constexpr auto operator=(const CFour &other) noexcept -> CFour & = default;
    constexpr auto operator=(CFour &&other) noexcept -> CFour & {
        *(CThree *)this = std::move(other);
        other.m_b = false;

        return *this;
    }

    constexpr ~CFour() override = default;

   private:
    bool m_b{};
};

#endif
