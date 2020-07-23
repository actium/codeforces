#include <array>
#include <iostream>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(std::array<unsigned, 6>& a)
{
    unsigned s = 0;
    for (const unsigned x : a)
        s += x;

    for (size_t i = 1; i < 5; ++i) {
        for (size_t j = i + 1; j < 6; ++j) {
            if (2 * (a[0] + a[i] + a[j]) == s)
                return answer(true);
        }
    }

    answer(false);
}

int main()
{
    std::array<unsigned, 6> a;
    std::cin >> a;

    solve(a);

    return 0;
}

