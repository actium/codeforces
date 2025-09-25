#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    std::vector<unsigned> f(1+n);
    for (const unsigned x : a)
        ++f[x];

    for (unsigned i = 1; i <= n; ++i) {
        if (f[i] % k != 0)
            return answer(0);

        f[i] /= k;
    }

    integer q = 0;
    {
        std::vector<unsigned> h(1+n);
        for (size_t i = 0, j = 0; i < n; --h[a[i++]]) {
            while (j < n && h[a[j]] < f[a[j]])
                ++h[a[j++]];

            q += j - i;
        }
    }

    answer(q);
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
