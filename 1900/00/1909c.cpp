#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& l, const std::vector<unsigned>& r, std::vector<unsigned>& c)
{
    const size_t n = c.size();

    std::set<unsigned> lb(l.begin(), l.end()), ub(r.begin(), r.end());

    std::vector<std::pair<unsigned, unsigned>> b(n);
    for (size_t i = 0; i < n; ++i) {
        const auto u = std::prev(lb.end()), v = ub.lower_bound(*u);
        b[i] = std::make_pair(*u, *v);
        lb.erase(u);
        ub.erase(v);
    }

    std::sort(b.begin(), b.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.second - lhs.first > rhs.second - rhs.first;
    });

    std::sort(c.begin(), c.end());

    integer s = 0;
    for (size_t i = 0; i < n; ++i)
        s += integer(b[i].second - b[i].first) * c[i];

    answer(s);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> l(n), r(n), c(n);
    std::cin >> l >> r >> c;

    solve(l, r, c);
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
