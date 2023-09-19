#include <iostream>
#include <vector>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(std::vector<size_t>& u)
{
    const size_t n = u.size();

    for (size_t i = n - 1; i > 0; --i)
        u[i-1] = std::min(u[i-1], u[i]);

    integer q = 0;
    for (size_t i = 0; i < n; ++i)
        q += u[i] - i;

    answer(q);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<size_t> u(n, n);
    for (size_t i = 0; i < m; ++i) {
        unsigned x, y;
        std::cin >> x >> y;

        if (--x > --y)
            std::swap(x, y);

        u[x] = std::min<size_t>(u[x], y);
    }

    solve(u);
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
