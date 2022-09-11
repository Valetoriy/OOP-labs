#ifndef CTHREE_HPP
#define CTHREE_HPP

#include "CTwo.hpp"

struct CThree : public CTwo {
    auto print() const noexcept -> void override {
        std::cout << "i: " << m_i << '\n';
        CTwo::print();
    }

    [[nodiscard]] constexpr auto i() const noexcept { return m_i; }

    constexpr CThree() noexcept = default;
    constexpr CThree(const CTwo &two, const int i) noexcept  // NOLINT
        : CTwo{two}, m_i{i} {}

    // Правило 5
    constexpr CThree(const CThree &other) noexcept = default;
    constexpr CThree(CThree &&other) noexcept
        : CTwo{std::move(other)}, m_i{other.m_i} {
        other.m_i = 0;
    }
    constexpr auto operator=(const CThree &other) noexcept
        -> CThree & = default;
    constexpr auto operator=(CThree &&other) noexcept -> CThree & {
        *(CTwo *)this = std::move(other);
        other.m_i = 0;

        return *this;
    }

    constexpr ~CThree() override = default;

   private:
    int m_i{};
};

#endif
