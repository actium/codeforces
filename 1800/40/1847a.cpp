#include <algorithm>
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

    std::vector<unsigned> d(n - 1);
    for (size_t i = 1; i < n; ++i) {
        d[i-1] = std::max(a[i-1], a[i]) - std::min(a[i-1], a[i]);
    }

    std::sort(d.begin(), d.end());

    unsigned p = 0;
    for (size_t i = 0; i < n - k; ++i)
        p += d[i];

    answer(p);
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
