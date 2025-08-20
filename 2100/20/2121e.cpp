#include <array>
#include <iostream>
#include <string>
#include <vector>

constexpr unsigned oo = ~0u >> 1;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned solve(const std::string& l, const std::string& r, size_t k, bool lb, bool ub, std::vector<std::array<unsigned, 4>>& memo)
{
    if (k == l.size())
        return 0;

    const size_t q = 2 * !!lb + !!ub;

    if (memo[k][q] == oo) {
        for (unsigned d = 0; d <= 9; ++d) {
            const unsigned ld = l[k] - '0', rd = r[k] - '0';
            if (lb && d < ld || ub && d > rd)
                continue;

            memo[k][q] = std::min(memo[k][q], solve(l, r, k+1, lb && d == ld, ub && d == rd, memo) + (d == ld) + (d == rd));
        }
    }
    return memo[k][q];
}

void solve(const std::string& l, const std::string& r)
{
    std::vector<std::array<unsigned, 4>> memo(l.size(), { oo, oo, oo, oo });

    answer(solve(l, r, 0, true, true, memo));
}

void test_case()
{
    std::string l, r;
    std::cin >> l >> r;

    solve(l, r);
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
