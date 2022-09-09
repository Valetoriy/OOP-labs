#ifndef TASK_9_HPP
#define TASK_9_HPP

#include <iostream>

template <typename Contained>
struct DynamicArray {
    auto input_elems() noexcept -> void {
        for (size_t ind{}; ind < m_capacity; ++ind) std::cin >> m_data[ind];
        m_size = m_capacity;
    }

    auto print_elems() const noexcept -> void {
        for (size_t ind{}; ind < m_size; ++ind) std::cout << m_data[ind] << ' ';
        puts("");
    }

    [[nodiscard]] constexpr auto max_elem() const noexcept -> Contained {
        if (m_size > 0) {
            Contained max{m_data[0]};
            for (size_t ind{1}; ind < m_capacity; ++ind)
                if (max < m_data[ind]) max = m_data[ind];

            return max;
        }

        return {};
    }

    constexpr auto insert(const size_t pos, const DynamicArray &other) noexcept
        -> void {
        if (pos > m_size) {
            size_t strt_size{other.m_size};
            for (size_t ind{}; ind < strt_size; ++ind)
                this->push_back(other[ind]);

            return;
        }

        DynamicArray temp{m_size + other.m_size};

        for (size_t ind{}; ind < pos; ++ind) temp.push_back(m_data[ind]);

        for (const auto &elem : other) temp.push_back(elem);

        for (size_t ind{pos}; ind < m_size; ++ind) temp.push_back(m_data[ind]);

        *this = std::move(temp);
    }

    constexpr auto push_back(const Contained &elem) noexcept -> void {
        if (m_size == m_capacity) {
            if (m_capacity > 0)
                reserve(m_capacity * 2);
            else
                reserve(1);
        }
        m_data[m_size] = elem;
        ++m_size;
    }

    constexpr auto reserve(const size_t &amount) noexcept -> void {
        if (amount > m_capacity) {
            auto new_data{new Contained[amount]};

            if (m_capacity > 0) {
                for (size_t i{}; i < m_size; ++i)
                    new_data[i] = std::move(m_data[i]);

                delete[](m_data);
            }
            m_data = new_data;
            m_capacity = amount;
        }
    }

    [[nodiscard]] constexpr auto size() const noexcept { return m_size; }
    [[nodiscard]] constexpr auto capacity() const noexcept {
        return m_capacity;
    }

    [[nodiscard]] constexpr auto operator[](const size_t &ind) const noexcept
        -> auto & {
        return m_data[ind];
    }

    constexpr DynamicArray() noexcept = default;
    constexpr explicit DynamicArray(const size_t cap) noexcept
        : m_data{new Contained[cap]}, m_capacity{cap} {}

    // Правило 5
    constexpr DynamicArray(const DynamicArray &other) noexcept {
        auto len{other.m_size};
        reserve(len);
        m_size = len;

        memcpy(m_data, other.m_data, m_size * sizeof(Contained));
    }
    constexpr DynamicArray(DynamicArray &&other) noexcept
        : m_data(other.m_data),
          m_size(other.m_size),
          m_capacity(other.m_capacity) {
        other.m_data = nullptr;
        other.m_size = 0;
        other.m_capacity = 0;
    }
    constexpr auto operator=(const DynamicArray &other) noexcept -> auto & {
        if (&other != this) {
            if (m_capacity > 0) {
                delete[](m_data);
                m_capacity = 0;
            }

            auto len{other.m_size};
            reserve(len);
            m_size = len;

            memcpy(m_data, other.m_data, m_size * sizeof(Contained));
        }
        return *this;
    }
    constexpr auto operator=(DynamicArray &&other) noexcept -> auto & {
        if (&other != this) {
            if (m_capacity > 0) delete[](m_data);

            m_data = other.m_data;
            m_size = other.m_size;
            m_capacity = other.m_capacity;

            other.m_data = nullptr;
            other.m_size = 0;
            other.m_capacity = 0;
        }
        return *this;
    }

    constexpr ~DynamicArray() noexcept { delete[](m_data); }

    [[nodiscard]] constexpr auto begin() const noexcept { return m_data; };
    [[nodiscard]] constexpr auto end() const noexcept {
        return m_data + m_size;
    };

   private:
    Contained *m_data{};
    size_t m_size{};
    size_t m_capacity{};
};

template <typename Elem1, typename... Elems>
DynamicArray(Elem1, Elems...) -> DynamicArray<Elem1>;

#endif
