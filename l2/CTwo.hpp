#ifndef CTWO_HPP
#define CTWO_HPP

#include "COne.hpp"

struct CTwo {
    auto print() const noexcept -> void {
        std::cout << "d: " << m_d << '\n';
        if (m_p != nullptr)
            m_p->print();
        else
            std::cout << "p: nullptr\n";
    }

    [[nodiscard]] constexpr auto d() const noexcept { return m_d; }
    [[nodiscard]] constexpr auto p() const noexcept { return m_p; }

    constexpr CTwo() noexcept = default;
    constexpr CTwo(const double d, const COne &p) noexcept  // NOLINT
        : m_d{d}, m_p{new COne{p}} {}                       // NOLINT

    // Правило 5
    constexpr CTwo(const CTwo &other) noexcept
        : m_d{other.m_d}, m_p{new COne{*other.m_p}} {}  // NOLINT
    constexpr CTwo(CTwo &&other) noexcept : m_d{other.m_d}, m_p{other.m_p} {
        other.m_d = 0;
        other.m_p = nullptr;
    }
    constexpr auto operator=(const CTwo &other) noexcept -> auto & {
        if (&other != this) {
            delete (m_p);
            m_d = other.m_d;
            m_p = new COne{*other.m_p};  // NOLINT
        }

        return *this;
    }
    constexpr auto operator=(CTwo &&other) noexcept -> auto & {
        if (&other != this) {
            delete (m_p);

            m_d = other.m_d;
            m_p = other.m_p;

            other.m_d = 0;
            other.m_p = nullptr;
        }

        return *this;
    }

    constexpr ~CTwo() { delete (m_p); }

   private:
    double m_d{};
    COne *m_p{};
};

#endif
