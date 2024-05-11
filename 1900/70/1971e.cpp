#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, const std::vector<unsigned>& d)
{
    const size_t m = d.size();

    std::vector<integer> t(m);
    for (size_t i = 0; i < m; ++i) {
        const size_t x = std::lower_bound(a.begin(), a.end(), d[i]) - a.begin();

        if (x == 0) {
            t[i] = 1ull * d[i] * b[0] / a[0];
        } else {
            t[i] = b[x-1] + integer(d[i] - a[x-1]) * (b[x] - b[x-1]) / (a[x] - a[x-1]);
        }
    }

    answer(t);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    size_t k, q;
    std::cin >> k >> q;

    std::vector<unsigned> a(k), b(k), d(q);
    std::cin >> a >> b >> d;

    solve(a, b, d);
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
