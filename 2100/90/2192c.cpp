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

void solve(const std::vector<unsigned>& a, unsigned h, unsigned k)
{
    const size_t n = a.size();

    std::vector<integer> sums(1+n);
    for (size_t i = 0; i < n; ++i)
        sums[i+1] = sums[i] + a[i];

    const auto q = h / sums[n], r = h % sums[n];
    if (r == 0)
        return answer(q * (n + k) - k);

    std::vector<unsigned> mins(1+n, ~0u), maxs(n+1);
    for (size_t i = 1; i <= n; ++i) {
        mins[i] = std::min(mins[i-1], a[i-1]);
        maxs[n-i] = std::max(maxs[n-i+1], a[n-i]);
    }

    for (size_t i = 1; i < n; ++i) {
        if (sums[i] >= r || sums[i] - mins[i] + maxs[i] >= r)
            return answer(q * (n + k) + i);
    }

    answer(q * (n + k) + n);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned h, k;
    std::cin >> h >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, h, k);
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
