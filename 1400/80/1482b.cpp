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

void answer(unsigned x, unsigned y)
{
    if (x == oo)
        std::cout << 0 << '\n';
    else
        std::cout << x << ' ' << y << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<int> d(n-1);
    for (size_t i = 1; i < n; ++i)
        d[i-1] = a[i] - a[i-1];

    std::sort(d.begin(), d.end());

    const size_t k = std::unique(d.begin(), d.end()) - d.begin();
    if (n == 1 || k == 1)
        return answer(oo, 0);

    if (k > 2 || (d[0] < 0) == (d[1] < 0))
        return no_answer();

    const unsigned c = d[1], m = c - d[0];
    if (a[0] >= m)
        return no_answer();

    for (size_t i = 1; i < n; ++i) {
        if ((a[i-1] + c) % m != a[i])
            return no_answer();
    }

    answer(m, c);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
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
