#include <iostream>

void answer(unsigned x, unsigned y, unsigned z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned n)
{
    if (n == 1)
        return no_answer();

    answer(n, n + 1, n * (n + 1));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
