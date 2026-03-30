#include <iostream>
#include <set>
#include <vector>

void answer(const std::vector<unsigned>& v, unsigned k)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';

    std::cout << k << '\n';
}

std::vector<std::pair<unsigned, unsigned>> factorize(unsigned n)
{
    std::vector<std::pair<unsigned, unsigned>> factors;
    for (unsigned i = 2; i * i <= n; ++i) {
        if (n % i != 0)
            continue;

        factors.emplace_back(i, 0);
        while (n % i == 0) {
            ++factors.back().second;
            n /= i;
        }
    }
    if (n != 1)
        factors.emplace_back(n, 1);

    return factors;
}

void solve(unsigned n)
{
    const auto factors = factorize(n);

    std::vector<unsigned> q = { 1 };
    {
        std::set<unsigned> s;
        for (const auto& [p, k] : factors) {
            for (unsigned i = 0; i < k; ++i) {
                for (size_t j = q.size(); j != 0; --j) {
                    const unsigned x = q[j-1] * p;
                    if (s.insert(x).second)
                        q.push_back(x);
                }
            }
        }
    }

    q[0] = q.back();
    q.pop_back();

    if (q[0] % q[1] != 0)
        std::swap(q.front(), q.back());

    answer(q, factors.size() == 2 && factors[0].second == 1 && factors[1].second == 1);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
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
