#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size();

    std::vector<unsigned> c(n);
    c[0] = b[0];
    for (size_t i = 1; i < n; ++i)
        c[i] = std::max(c[i-1], b[i]);

    size_t k = n;
    for (size_t i = 0; i < n; ++i) {
        const size_t m = std::distance(c.cbegin(), std::lower_bound(c.cbegin(), c.cend(), a[i]));
        k = std::min(k, i + m);
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
