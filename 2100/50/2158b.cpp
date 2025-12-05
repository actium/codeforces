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

void solve(const std::vector<unsigned>& a)
{
    const size_t m = a.size();

    std::vector<unsigned> f(1 + m);
    for (const unsigned x : a)
        ++f[x];

    unsigned q = m / 2, d = 2, k = 0;
    for (unsigned i = 1; i <= m; ++i) {
        if (f[i] == 0)
            continue;

        if (f[i] % 2 == 0) {
            k += 2;
        } else {
            k += 1;
            d = 0;
        }

        --q;
    }

    k -= q % 2 * d;

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(2 * n);
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
