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
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    std::vector<size_t> o(n);
    for (size_t i = 0; i < n; ++i)
        o[i] = i;

    std::sort(o.begin(), o.end(), [&](size_t x, size_t y) { return a[x] > a[y]; });

    std::vector<size_t> p;
    for (size_t i = 0, j = 0; i < n; ++i) {
        if (a[o[i]] != a[o[j]])
            j = i;

        if (i - j < k)
            p.push_back(o[i]);
    }

    const size_t m = p.size() - p.size() % k;

    std::vector<unsigned> c(n);
    for (size_t i = 0; i < m; ++i)
        c[p[i]] = 1 + i % k;

    answer(c);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

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
