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

void solve(unsigned n, std::array<unsigned, 4>& d)
{
    const auto test = [&](unsigned x) {
        for (size_t i = 0; i < 4; ++i) {
            const bool c1 = x & 1 << i, c2 = x & 1 << (i + 3) % 4;
            if (d[i] < c1 + c2 || d[i] - c1 - c2 > n - 2)
                return false;
        }
        return true;
    };

    for (unsigned i = 0; i < 16; ++i) {
        if (test(i))
            return answer(true);
    }

    answer(false);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    std::array<unsigned, 4> d;
    std::cin >> d;

    solve(n, d);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
