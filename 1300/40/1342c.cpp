#include <iostream>
#include <numeric>
#include <vector>

using integer = unsigned long long;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<integer>& v)
{
    const char* separator = "";
    for (const integer x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned a, unsigned b, const std::vector<std::pair<integer, integer>>& r)
{
    const size_t m = r.size();

    if (a > b)
        std::swap(a, b);

    const unsigned p = std::lcm(a, b);

    const auto count = [=](integer x) {
        const integer q = x / p, r = x % p;
        return q * (p - b) + (r > b ? r - b : 0);
    };

    std::vector<integer> v(m);
    if (b % a != 0) {
        for (size_t i = 0; i < m; ++i)
            v[i] = count(r[i].second + 1) - count(r[i].first);
    }

    answer(v);
}

void test_case()
{
    unsigned a, b;
    std::cin >> a >> b;

    size_t q;
    std::cin >> q;

    std::vector<std::pair<integer, integer>> r(q);
    std::cin >> r;

    solve(a, b, r);
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
