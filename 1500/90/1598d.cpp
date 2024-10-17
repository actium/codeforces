#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& t)
{
    const size_t n = t.size();

    std::vector<unsigned> f[2];
    for (size_t i = 0; i < 2; ++i)
        f[i].resize(1+n);

    for (const auto& e : t) {
        ++f[0][e.first];
        ++f[1][e.second];
    }

    integer k = n * (n - 1ull) * (n - 2) / 6;
    for (const auto& e : t)
        k -= (f[0][e.first] - 1ull) * (f[1][e.second] - 1);

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> t(n);
    std::cin >> t;

    solve(t);
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
