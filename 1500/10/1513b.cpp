#include <iostream>
#include <vector>

constexpr unsigned M = 1000000007;

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

unsigned f[200000];

void initialize()
{
    f[0] = 1;

    for (unsigned i = 1; i < 200000; ++i)
        f[i] = 1ull * f[i-1] * i % M;
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned x = a[0];
    for (size_t i = 1; i < n; ++i)
        x &= a[i];

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i)
        k += (a[i] == x);

    answer(k * (k - 1ull) % M * f[n-2] % M);
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
    initialize();

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
