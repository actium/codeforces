#include <iostream>
#include <utility>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned x)
{
    unsigned a = 0, b = 0, c = 0, k = 0;
    while (a < x) {
        a = std::exchange(b, std::exchange(c, 2 * b + 1));
        ++k;
    }

    answer(k);
}

void test_case()
{
    unsigned x;
    std::cin >> x;

    solve(x);
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
