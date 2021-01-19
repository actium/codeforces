#include <algorithm>
#include <iostream>
#include <vector>

std::vector<unsigned> primes()
{
    static std::vector<unsigned> p;

    if (p.empty()) {
        constexpr size_t k = 20202;

        std::vector<bool> c(k);
        for (size_t i = 2; i < k; ++i) {
            if (c[i])
                continue;

            p.push_back(i);

            for (size_t j = 2 * i; j < k; j += i)
                c[j] = true;
        }
    }

    return p;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned d)
{
    const std::vector<unsigned>& p = primes();

    const auto x = std::lower_bound(p.cbegin(), p.cend(), 1 + d);
    const auto y = std::lower_bound(x, p.cend(), *x + d);

    answer(*x * *y);
}

void test_case()
{
    unsigned d;
    std::cin >> d;

    solve(d);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

