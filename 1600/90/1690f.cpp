#include <iostream>
#include <numeric>
#include <string>
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

void search(const std::string& s, const std::vector<unsigned>& p, size_t u, size_t x, unsigned k, std::vector<unsigned>& d)
{
    if (s[u] == s[x])
        d.push_back(k);

    if (u != x)
        search(s, p, p[u]-1, x, k+1, d);
}

unsigned cycle_length(const std::vector<unsigned>& d)
{
    const unsigned m = d.back();

    std::vector<bool> v(1 + m);
    for (const unsigned x : d)
        v[x] = true;

    const auto check = [&](unsigned x) {
        if (m % x != 0)
            return false;

        for (unsigned i = x; i < m; i += x) {
            if (!v[i])
                return false;
        }
        return true;
    };

    for (const unsigned x : d) {
        if (check(x))
            return x;
    }
    return m;
}

void solve(const std::string& s, const std::vector<unsigned>& p)
{
    const size_t n = s.size();

    integer x = 1;
    for (size_t i = 0; i < n; ++i) {
        std::vector<unsigned> d;
        search(s, p, p[i]-1, i, 1, d);

        x = std::lcm(x, cycle_length(d));
    }

    answer(x);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(s, p);
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
