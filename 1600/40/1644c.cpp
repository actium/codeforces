#include <iostream>
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

void solve(const std::vector<int>& a, unsigned x)
{
    constexpr integer oo = 5000 * 100000;

    const size_t n = a.size();

    std::vector<integer> ps(1 + n);
    for (size_t i = 0; i < n; ++i)
        ps[i+1] = ps[i] + a[i];

    std::vector<integer> bs(n, -oo);
    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 0; j < i; ++j)
            bs[i-j-1] = std::max(bs[i-j-1], ps[i] - ps[j]);
    }

    std::vector<integer> f(1 + n);
    for (size_t k = 0; k <= n; ++k) {
        for (size_t i = 0; i < n; ++i)
            f[k] = std::max<integer>(f[k], bs[i] + std::min(i + 1, k) * x);
    }

    answer(f);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned x;
    std::cin >> x;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a, x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

