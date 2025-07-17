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

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> f(1+n);
    for (const unsigned x : a)
        ++f[x];

    unsigned x = 0;
    while (x <= n && f[x] != 0)
        ++x;

    std::sort(f.begin(), f.begin() + x);

    std::vector<unsigned> c(1+n, 1);
    for (size_t i = 0, k = 1; x + k <= n; ++k) {
        while (i < x && f[i] == k)
            ++i;

        c[k] = i + 1;
    }

    for (size_t i = 0; i < x; ++i)
        c[n-i] = i + 1;

    answer(c);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
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
