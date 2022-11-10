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

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size(), k = 1 << n;

    unsigned g = a[0];
    for (size_t i = 1; i < n; ++i)
        g = std::gcd(g, a[i]);

    if (g == 1)
        return answer(0);

    if (std::gcd(g, std::gcd(a[n-1], n)) == 1)
        return answer(1);

    if (std::gcd(g, std::gcd(a[n-2], n - 1)) == 1)
        return answer(2);

    answer(3);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
