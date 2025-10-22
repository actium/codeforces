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

void solve(std::vector<unsigned>& a, unsigned k)
{
    const size_t n = a.size();

    for (k = std::min(k, 2 + k % 2); k != 0; --k) {
        std::vector<unsigned> f(1 + n + 1);
        for (const unsigned x : a)
            ++f[x];

        unsigned x = 0;
        while (f[x] != 0)
            ++x;

        for (size_t i = 0; i < n; ++i) {
            if (a[i] > x || f[a[i]] > 1)
                a[i] = x;
        }
    }

    integer v = 0;
    for (const unsigned x : a)
        v += x;

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

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
