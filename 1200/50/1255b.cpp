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

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(unsigned c, const std::vector<std::pair<size_t, size_t>>& p)
{
    std::cout << c << '\n';

    for (const auto& e : p)
        std::cout << 1 + e.first << ' ' << 1 + e.second << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned m)
{
    const size_t n = a.size();
    if (n < 3 || m < n)
        return no_answer();

    std::vector<size_t> order(n);
    for (size_t i = 0; i < n; ++i)
        order[i] = i;

    std::sort(order.begin(), order.end(), [&a](size_t x, size_t y) { return a[x] < a[y]; });

    std::vector<std::pair<size_t, size_t>> p(n);
    unsigned c = 0;
    for (size_t i = 0; i < n; ++i) {
        p[i].first = order[i];
        p[i].second = order[(i+1) % n];
        c += a[p[i].first] + a[p[i].second];
    }
    for (m -= n; m > 0; --m) {
        p.emplace_back(order[0], order[1]);
        c += a[p.back().first] + a[p.back().second];
    }

    answer(c, p);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, m);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

