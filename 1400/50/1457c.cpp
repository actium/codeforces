#include <iostream>
#include <string>
#include <vector>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& a, size_t p, size_t k, unsigned x, unsigned y)
{
    const size_t n = a.length();

    std::vector<unsigned> c(n);
    for (size_t i = n; i-- > 0; ) {
        if (i + k < n)
            c[i] = c[i+k];

        if (a[i] == '0')
            c[i] += x;
    }

    unsigned b = ~0u;
    for (size_t i = p-1; i < n; ++i)
        b = std::min<unsigned>(b, c[i] + (i - (p-1)) * y);

    answer(b);
}

void test_case()
{
    size_t n, p, k;
    std::cin >> n >> p >> k;

    std::string a;
    std::cin >> a;

    unsigned x, y;
    std::cin >> x >> y;

    solve(a, p, k, x, y);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

