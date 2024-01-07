#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "Alice", "Bob" };
    std::cout << s[v] << '\n';
}

void solve(unsigned a, unsigned b)
{
    answer((a + b) % 2 == 0);
}

void test_case()
{
    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);
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
