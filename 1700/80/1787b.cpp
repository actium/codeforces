#include <algorithm>
#include <iostream>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    using factor_t = std::pair<unsigned, unsigned>;

    std::vector<factor_t> f;
    for (unsigned i = 2; i * i <= n; ++i) {
        if (n % i != 0)
            continue;

        unsigned p = 0;
        while (n % i == 0) {
            ++p;
            n /= i;
        }
        f.emplace_back(i, p);
    }
    if (n != 1)
        f.emplace_back(n, 1);

    std::sort(f.begin(), f.end(), [](const factor_t& x, const factor_t& y) {
        return x.second > y.second;
    });

    unsigned s = 0;
    while (!f.empty()) {
        const unsigned p = f.back().second;

        unsigned a = 1;
        for (factor_t& x : f) {
            a *= x.first;
            x.second -= p;
        }

        s += a * p;

        while (!f.empty() && f.back().second == 0)
            f.pop_back();
    }

    answer(s);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
