#include <iostream>
#include <map>
#include <vector>

#include <cmath>

using integer = long long;

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

integer count(integer x, integer y, const std::map<int, integer>& f)
{
    const integer d = x * x - 4 * y;
    if (d < 0)
        return 0;

    integer r = sqrt(d);
    if (r * r < d)
        ++r;

    const integer a = (x - r) / 2, b = (x + r) / 2;
    if (a + b != x || a * b != y)
        return 0;

    const auto it = f.find((x - r) / 2);
    if (it == f.end())
        return 0;

    const auto jt = f.find((x + r) / 2);
    if (jt == f.end())
        return 0;

    return it == jt ? it->second * (jt->second - 1) / 2 : it->second * jt->second;
}

void solve(std::vector<int>& a, const std::vector<std::pair<int, integer>>& r)
{
    const size_t q = r.size();

    std::map<int, integer> f;
    for (const int x : a)
        ++f[x];

    std::vector<integer> c(q);
    for (size_t i = 0; i < q; ++i)
        c[i] = count(r[i].first, r[i].second, f);

    answer(c);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    size_t q;
    std::cin >> q;

    std::vector<std::pair<int, integer>> r(q);
    std::cin >> r;

    solve(a, r);
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
