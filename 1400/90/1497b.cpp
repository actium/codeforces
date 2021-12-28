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

void solve(const std::vector<unsigned>& a, unsigned m)
{
    std::vector<unsigned> f(m);
    for (const unsigned x : a)
        ++f[x % m];

    unsigned k = (f[0] != 0);
    for (unsigned i = 1; i < m; ++i) {
        if (f[i] == 0)
            continue;

        if (2 * i < m || f[m-i] == 0) {
            const unsigned c = std::min(f[i], f[m-i]);
            const unsigned d = std::max(f[i], f[m-i]);
            k += 1 + (d == c ? 0 : d - 1 - c);
        }

        if (2 * i == m)
            ++k;
    }

    answer(k);
}

void test_case()
{
    unsigned n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, m);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
