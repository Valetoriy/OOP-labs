#ifndef CONE_HPP
#define CONE_HPP

#include <cstring>
#include <iostream>

struct COne {
    auto print() const noexcept -> void {
        if (m_ps != nullptr)
            std::cout << "ps: " << m_ps << '\n';
        else
            std::cout << "ps: nullptr\n";
        std::cout << "l: " << m_l << '\n';
    }

    [[nodiscard]] constexpr auto ps() const noexcept { return m_ps; };
    [[nodiscard]] constexpr auto l() const noexcept { return m_l; };

    constexpr COne() noexcept = default;
    constexpr COne(const char *ps, const long l) noexcept  // NOLINT
        : m_ps{new char[l]}, m_l{l} {                      // NOLINT
        memcpy(m_ps, ps, (size_t)m_l);
    }

    // Правило 5
    constexpr COne(const COne &other) noexcept
        : m_ps{new char[other.m_l]}, m_l{other.m_l} {  // NOLINT
        memcpy(m_ps, other.m_ps, (size_t)m_l);
    }
    constexpr COne(COne &&other) noexcept : m_ps{other.m_ps}, m_l{other.m_l} {
        other.m_ps = nullptr;
        other.m_l = 0;
    }
    constexpr auto operator=(const COne &other) noexcept -> auto & {
        if (&other != this) {
            delete[](m_ps);
            m_ps = new char[other.m_l];  // NOLINT
            m_l = other.m_l;
            memcpy(m_ps, other.m_ps, (size_t)m_l);
        }

        return *this;
    }
    constexpr auto operator=(COne &&other) noexcept -> auto & {
        if (&other != this) {
            delete[](m_ps);

            m_ps = other.m_ps;
            m_l = other.m_l;

            other.m_ps = nullptr;
            other.m_l = 0;
        }

        return *this;
    }

    constexpr ~COne() { delete[](m_ps); }

   private:
    char *m_ps{};
    long m_l{};
};

#endif
