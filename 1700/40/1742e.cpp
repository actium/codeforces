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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& k)
{
    const size_t n = a.size(), q = k.size();

    std::vector<integer> s(1 + n), b(1 + n);
    for (size_t i = 0; i < n; ++i) {
        s[1 + i] = s[i] + a[i];
        b[1 + i] = std::max<unsigned>(b[i], a[i]);
    }

    std::vector<integer> y(q);
    for (size_t i = 0; i < q; ++i) {
        const auto it = std::upper_bound(b.cbegin(), b.cend(), k[i]);
        y[i] = s[it - b.cbegin() - 1];
    }

    answer(y);
}

void test_case()
{
    size_t n, q;
    std::cin >> n >> q;

    std::vector<unsigned> a(n), k(q);
    std::cin >> a >> k;

    solve(a, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
