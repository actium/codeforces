#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned a, unsigned b, unsigned c)
{
    const auto evaluate = [](unsigned a, unsigned b) {
        return std::max(a, b) - std::min(a, b);
    };

    const auto u = evaluate(a, b), v = evaluate(a + c, b);
    answer(std::max(u, v));
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
