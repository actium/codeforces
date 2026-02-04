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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    if (std::is_sorted(a.begin(), a.end()))
        return no_answer();

    std::vector<unsigned> b = a;
    std::sort(b.begin(), b.end());

    unsigned d = ~0u;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] != b[i])
            d = std::min(d, std::max(a[i] - b[0], b[n-1] - a[i]));
    }

    answer(d);
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
