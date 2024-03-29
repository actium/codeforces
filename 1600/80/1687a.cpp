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

    integer s = 0;
    if (k <= n) {
        for (size_t i = 0; i < k; ++i)
            s += a[i];

        integer b = s;
        for (size_t i = k; i < n; ++i) {
            s -= a[i-k];
            s += a[i];
            b = std::max(b, s);
        }

        s = b + (k - 1ull) * k / 2;
    } else {
        for (size_t i = 0; i < n; ++i)
            s += k - 1ull + a[i] - i;
    }

    answer(s);
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
