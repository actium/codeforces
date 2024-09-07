#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& c, unsigned a, unsigned b)
{
    const size_t n = c.size();

    const unsigned g = std::gcd(a, b);
    for (unsigned& x : c)
        x %= g;

    std::sort(c.begin(), c.end());

    unsigned d = 0;
    for (size_t i = 1; i < n; ++i)
        d = std::max(d, c[i] - c[i-1]);

    answer(std::min(c[n-1] - c[0], g - d));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned a, b;
    std::cin >> a >> b;

    std::vector<unsigned> c(n);
    std::cin >> c;

    solve(c, a, b);
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
