#include <iostream>
#include <vector>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(std::vector<std::pair<unsigned, integer>>& a, unsigned x)
{
    for (size_t i = 0; i < a.size() && a[i].first % x == 0; ++i)
        a.emplace_back(a[i].first / x, a[i].second * x);

    integer s = 0;
    for (const auto& q : a)
        s += q.first * q.second;

    answer(s);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned x;
    std::cin >> x;

    std::vector<std::pair<unsigned, integer>> a(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> a[i].first;
        a[i].second = 1;
    }

    solve(a, x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

