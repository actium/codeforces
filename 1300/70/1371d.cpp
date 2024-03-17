#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void answer(unsigned u, const std::vector<std::string>& v)
{
    std::cout << u << '\n';

    for (const std::string& x : v)
        std::cout << x << '\n';
}

void solve(unsigned n, unsigned k)
{
    std::vector<std::string> a(n, std::string(n, '0'));
    for (size_t r = 0, c = 0; k != 0; --k) {
        ++a[r][c];
        r = (r + 1) % n;
        c = (c + (r != 0)) % n;
    }

    std::vector<unsigned> r(n), c(n);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            r[i] += a[i][j] - '0';
            c[j] += a[i][j] - '0';
        }
    }

    const auto rr = std::minmax_element(r.begin(), r.end());
    const auto rc = std::minmax_element(c.begin(), c.end());

    const unsigned dr = *rr.second - *rr.first, dc = *rc.second - *rc.first;

    answer(dr * dr + dc * dc, a);
}

void test_case()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);
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
