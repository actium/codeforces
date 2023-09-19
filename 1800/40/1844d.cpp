#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    unsigned k = 2;
    while (n % k == 0)
        ++k;

    std::string s(n, 'a');
    for (size_t i = 1; i < n; ++i)
        s[i] += i % k;

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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
