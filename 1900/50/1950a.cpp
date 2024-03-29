#include <iostream>

void answer(const char* x)
{
    std::cout << x << '\n';
}

void solve(unsigned a, unsigned b, unsigned c)
{
    if (a < b && b < c)
        return answer("STAIR");

    if (a < b && b > c)
        return answer("PEAK");

    answer("NONE");
}

void test_case()
{
    unsigned a, b, c;
    std::cin >> a >> b >> c;

    solve(a, b, c);
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
