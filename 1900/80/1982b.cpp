#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned x, unsigned y, unsigned k)
{
    while (x != 1) {
        const unsigned d = y - x % y;
        if (k < d)
            return answer(x + k);

        x += d;
        while (x % y == 0)
            x /= y;

        k -= d;
    }

    answer(k % (y - 1) + 1);
}

void test_case()
{
    unsigned x, y, k;
    std::cin >> x >> y >> k;

    solve(x, y, k);
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
