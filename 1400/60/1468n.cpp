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

void solve(std::array<unsigned, 3>& c, std::array<unsigned, 5>& a)
{
    const auto put = [&](size_t i, size_t j) {
        const unsigned k = std::min(a[i], c[j]);
        a[i] -= k, c[j] -= k;
    };

    put(0, 0);
    put(1, 1);
    put(2, 2);
    put(3, 0);
    put(3, 2);
    put(4, 1);
    put(4, 2);

    answer(a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0);
}

void test_case()
{
    std::array<unsigned, 3> c;
    std::cin >> c;

    std::array<unsigned, 5> a;
    std::cin >> a;

    solve(c, a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

