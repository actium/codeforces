#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned a, unsigned b, unsigned c)
{
    a = std::min(a, b);
    a = std::min(a, c);
    
    answer(n - a);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    unsigned a, b, c;
    std::cin >> a >> b >> c;

    solve(n, a, b, c);
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
