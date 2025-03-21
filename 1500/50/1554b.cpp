#include <iostream>
#include <vector>

#include <climits>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(long long x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    long long v = LONG_LONG_MIN;
    for (size_t i = 2 * k < n ? n - 2 * k : 1; i < n; ++i) {
        for (size_t j = 0; j < i; ++j)
            v = std::max<long long>(v, (i + 1LL) * (j + 1) - k * (a[i] | a[j]));
    }

    answer(v);
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
