#include <iostream>

using integer = unsigned long long;

void answer(bool v)
{
    constexpr const char* s[2] = { "Alice", "Bob" };
    std::cout << s[v] << '\n';
}

void solve(integer p, integer q)
{
    answer(p < q && std::min(p / 2, q / 3) >= q - p);
}

void test_case()
{
    integer p, q;
    std::cin >> p >> q;

    solve(p, q);
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
