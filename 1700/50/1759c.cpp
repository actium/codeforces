#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(int l, int r, unsigned x, int a, int b)
{
    if (a == b)
        return answer(0);

    if (std::abs(a - b) >= x)
        return answer(1);

    if (r - std::max(a, b) >= x || std::min(a, b) - l >= x)
        return answer(2);

    if (r - b >= x && a - l >= x || r - a >= x && b - l >= x)
        return answer(3);

    no_answer();
}

void test_case()
{
    int l, r;
    std::cin >> l >> r;

    unsigned x;
    std::cin >> x;

    int a, b;
    std::cin >> a >> b;

    solve(l, r, x, a, b);
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
