#include <iostream>
#include <numeric>
#include <vector>

using integer = unsigned long long;

using sector_t = std::pair<integer, integer>;

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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(integer n, integer m, const std::vector<std::pair<sector_t, sector_t>>& r)
{
    const integer x = std::gcd(n, m), d[2] = { n / x, m / x };

    for (const auto& q : r)
        answer((q.first.second - 1) / d[q.first.first-1] == (q.second.second - 1) / d[q.second.first-1]);
}

int main()
{
    integer n, m;
    std::cin >> n >> m;

    size_t q;
    std::cin >> q;

    std::vector<std::pair<sector_t, sector_t>> r(q);
    std::cin >> r;

    solve(n, m, r);

    return 0;
}
