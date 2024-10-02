#include <iostream>
#include <map>
#include <vector>

using integer = long long;

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

void solve(const std::vector<unsigned>& x, const std::vector<integer>& r)
{
    const size_t n = x.size(), k = r.size();

    std::map<unsigned, integer> d;
    for (size_t i = 0; i + 1 < n; ++i)
        d[x[i]] += n - i - 1;
    for (size_t i = 1; i < n; ++i)
        d[x[i]+1] -= i;

    std::map<integer, integer> c;
    for (auto it = d.begin(), jt = std::next(it); jt != d.end(); it = jt++) {
        c[it->second] += jt->first - it->first;
        jt->second += it->second;
    }

    std::vector<integer> v(k);
    for (size_t i = 0; i < k; ++i)
        v[i] = c[r[i]];

    answer(v);
}

void test_case()
{
    size_t n, q;
    std::cin >> n >> q;

    std::vector<unsigned> x(n);
    std::cin >> x;

    std::vector<integer> r(q);
    std::cin >> r;

    solve(x, r);
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
