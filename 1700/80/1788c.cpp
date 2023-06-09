#include <iostream>
#include <vector>

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    std::cout << "Yes" << '\n';
    for (const std::pair<unsigned, unsigned>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void no_answer()
{
    std::cout << "No" << '\n';
}

void solve(unsigned n)
{
    if (n % 2 == 0)
        return no_answer();

    std::vector<std::pair<unsigned, unsigned>> ps;
    for (unsigned i = 1; i <= n; i += 2)
        ps.emplace_back(i, 2 * n - i / 2);
    for (unsigned i = 2; i < n; i += 2)
        ps.emplace_back(i, n + (n - i) / 2 + 1);

    answer(ps);
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
