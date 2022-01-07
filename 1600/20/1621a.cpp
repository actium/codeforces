#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<std::string>& v)
{
    for (const std::string x : v)
        std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned n, unsigned k)
{
    if (k > (n + 1) / 2)
        return no_answer();

    std::vector<std::string> p(n, std::string(n, '.'));
    for (size_t i = 0; i < n && k > 0; i += 2, --k)
        p[i][i] = 'R';

    answer(p);
}

void test_case()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
