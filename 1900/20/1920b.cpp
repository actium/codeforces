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

void answer(int x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a, size_t k, size_t x)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    std::vector<unsigned> ps(1 + n);
    for (size_t i = 0; i < n; ++i)
        ps[i+1] = ps[i] + a[i];

    int s = ps[n] - 2 * (ps[n] - ps[n-x]);
    for (size_t i = 1; i <= k; ++i)
        s = std::max<int>(s, ps[n-i] - 2 * (ps[n-i] - ps[std::max<int>(n-i-x, 0)]));

    answer(s);
}

void test_case()
{
    size_t n, k, x;
    std::cin >> n >> k >> x;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k, x);
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
