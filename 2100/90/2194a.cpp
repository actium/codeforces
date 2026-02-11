#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned w)
{
    answer(n - n / w);
}

void test_case()
{
    unsigned n, w;
    std::cin >> n >> w;

    solve(n, w);
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
