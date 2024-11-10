#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned l, unsigned r, unsigned k)
{
    if (1ull * l * k > r)
        return answer(0);

    answer(r / k - l + 1);
}

void test_case()
{
    unsigned l, r, k;
    std::cin >> l >> r >> k;

    solve(l, r, k);
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
