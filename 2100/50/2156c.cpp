#include <iostream>
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

void solve(const std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    std::vector<unsigned> f(1+n);
    for (const unsigned x : a)
        ++f[x];

    std::vector<unsigned> p(1+n);
    for (size_t i = 1; i <= n; ++i)
        p[i] = p[i-1] + f[i];

    unsigned x = 1;
    for (size_t i = 2; i <= n; ++i) {
        const unsigned b = std::min(4 * i - 1, n);

        unsigned c = p[b];
        for (unsigned t = i; t <= b; t += i)
            c -= f[t];

        if (c <= k)
            x = i;
    }

    answer(x);
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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
