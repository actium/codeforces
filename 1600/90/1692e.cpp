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

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned s)
{
    const size_t n = a.size();

    std::vector<unsigned> ps(1 + n);
    for (size_t i = 0; i < n; ++i)
        ps[i+1] = ps[i] + a[i];

    if (ps[n] < s)
        return no_answer();

    unsigned k = ~0u;
    for (size_t i = 0; i < n && ps[n-i] >= s; ++i) {
        const auto it = std::lower_bound(ps.cbegin(), ps.cend(), ps[n-i] - s);
        k = std::min<unsigned>(k, it - ps.cbegin() + i);
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned s;
    std::cin >> s;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
