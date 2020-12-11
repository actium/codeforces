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

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void recurse(const std::vector<unsigned>& a, size_t lb, size_t ub, const std::vector<integer>& p, std::set<integer>& t)
{
    t.insert(p[ub] - p[lb]);

    const size_t x = std::upper_bound(a.cbegin() + lb, a.cbegin() + ub, (a[lb] + a[ub-1]) / 2) - a.cbegin();
    if (x != ub) {
        recurse(a, lb, x, p, t);
        recurse(a, x, ub, p, t);
    }
}

void solve(std::vector<unsigned>& a, const std::vector<unsigned>& s)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    std::vector<integer> p(1+n);
    for (size_t i = 1; i <= n; ++i)
        p[i] = p[i-1] + a[i-1];

    std::set<integer> t;
    recurse(a, 0, n, p, t);

    for (const unsigned x : s)
        answer(t.count(x) != 0);
}

void test_case()
{
    size_t n, q;
    std::cin >> n >> q;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<unsigned> s(q);
    std::cin >> s;

    solve(a, s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

