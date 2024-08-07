#include <algorithm>
#include <iostream>
#include <vector>

constexpr unsigned oo = ~0u;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

std::vector<unsigned> divisors(unsigned x)
{
    std::vector<unsigned> d;
    for (unsigned i = 1; i * i <= x; ++i) {
        if (x % i != 0)
            continue;

        d.push_back(i);

        if (i * i != x)
            d.push_back(x / i);
    }
    return d;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::vector<unsigned>& a, size_t m)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    unsigned d = oo;
    {
        std::vector<unsigned> f(1+m);
        for (size_t i = 0, j = 0, k = 0; j < n; ++j) {
            for (const unsigned x : divisors(a[j])) {
                if (x <= m)
                    k += (f[x]++ == 0);
            }

            while (k == m) {
                d = std::min(d, a[j] - a[i]);

                for (const unsigned x : divisors(a[i++])) {
                    if (x <= m)
                        k -= (--f[x] == 0);
                }
            }
        }
    }

    d != oo ? answer(d) : no_answer();
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, m);
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
