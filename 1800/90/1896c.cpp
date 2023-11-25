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

void answer(const std::vector<unsigned>& v)
{
    std::cout << "YES" << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::vector<unsigned>& a, std::vector<unsigned>& b, size_t x)
{
    const size_t n = a.size();

    std::vector<size_t> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = i;

    std::sort(p.begin(), p.end(), [&](size_t i, size_t j) { return a[i] > a[j]; });

    std::sort(b.begin(), b.end());

    std::vector<unsigned> c(n);
    for (size_t i = 0; i < n; ++i)
        c[p[i]] = (i < x ? b[x-1-i] : b[n-1-(i-x)]);

    size_t k = 0;
    for (size_t i = 0; i < n; ++i)
        k += (a[i] > c[i]);

    k == x ? answer(c) : no_answer();
}

void test_case()
{
    size_t n, x;
    std::cin >> n >> x;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b, x);
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
