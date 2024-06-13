#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned m, unsigned x)
{
    while (--x != 0) {
        if (n < 2 || m < 2)
            return answer(0);

        n -= 2;
        m -= 2;
    }

    if (n == 0 || m == 0)
        return answer(0);

    if (n == 1 && m == 1)
        return answer(1);

    answer(n + m - 2);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, m;
    std::cin >> n >> m;

    unsigned x;
    std::cin >> x;

    solve(n, m, x);

    return 0;
}
