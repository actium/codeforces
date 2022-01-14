#include <algorithm>
#include <iostream>
#include <vector>

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1+x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<std::pair<unsigned, size_t>>& a)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    std::vector<unsigned long long> ps(1+n);
    for (size_t i = 0; i < n; ++i)
        ps[i+1] = ps[i] + a[i].first;

    std::vector<bool> p(n, true);
    for (size_t i = n-1; i-- > 0; )
        p[i] = p[i+1] * (a[i].first + ps[i] >= a[i+1].first);

    std::vector<size_t> v;
    for (size_t i = 0; i < n; ++i) {
        if (p[i])
            v.push_back(a[i].second);
    }

    std::sort(v.begin(), v.end());

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, size_t>> a(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> a[i].first;
        a[i].second = i;
    }

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
