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

void answer(unsigned x, const std::vector<std::pair<unsigned, unsigned>>& y)
{
    std::cout << x << '\n';

    for (const std::pair<unsigned, unsigned> p : y)
        std::cout << p.first << ' ' << p.second << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size() / 2;

    std::sort(a.begin(), a.end());

    std::vector<std::pair<unsigned, unsigned>> ps(n);
    for (size_t i = 0; i < n; ++i) {
        ps[i].first = a[i];
        ps[i].second = a[2*n-1-i];
    }

    answer(ps[n-1].first - ps[0].first + ps[0].second - ps[n-1].second, ps);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(2 * n);
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
