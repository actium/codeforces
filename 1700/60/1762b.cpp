#include <algorithm>
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

void answer(const std::vector<std::pair<size_t, integer>>& v)
{
    std::cout << v.size() << '\n';
    for (const std::pair<size_t, integer> x : v)
        std::cout << 1 + x.first << ' ' << x.second << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<std::pair<integer, size_t>> x(n);
    for (size_t i = 0; i < n; ++i) {
        x[i].first = a[i];
        x[i].second = i;
    }

    std::sort(x.begin(), x.end());

    std::vector<std::pair<size_t, integer>> p;
    for (size_t i = 1; i < n; ++i) {
        if (x[i].first < x[i-1].first) {
            p.emplace_back(x[i].second, x[i-1].first - x[i].first);
            x[i].first = x[i-1].first;
        }

        const integer r = x[i].first % x[i-1].first;
        if (r != 0) {
            p.emplace_back(x[i].second, x[i-1].first - r);
            x[i].first += x[i-1].first - r;
        }
    }

    answer(p);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
