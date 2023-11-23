#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "Second", "First" };
    std::cout << s[v] << '\n';
}

void solve(unsigned n)
{
    answer(n % 3 == 1 || n % 3 == 2);
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
