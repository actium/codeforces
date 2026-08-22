#include <array>
#include <iostream>
#include <vector>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::array<unsigned, 4>>& bs)
{
    const size_t n = bs.size();

    const auto check = [&](size_t m) {
        size_t k = 0;
        for (size_t i = 0; i < n && k < m; ++i) {
            const auto l = bs[i][0], r = bs[i][1], u = bs[i][2], v = bs[i][3];
            if ((k + 1 < l || k + 1 > r) && (m - k < u || m - k > v))
                ++k;
        }
        return k == m;
    };

    size_t m = n;
    while (!check(m))
        --m;

    answer(m);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::array<unsigned, 4>> bs(n);
    std::cin >> bs;

    solve(bs);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
