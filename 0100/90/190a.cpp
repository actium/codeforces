#include <iostream>

void no_answer()
{
    std::cout << "Impossible" << '\n';
}

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned n, unsigned m)
{
    if (n == 0 && m != 0)
        return no_answer();

    if (m == 0)
        return answer(n, n);

    answer(n + m - std::min(m, n), n + m - 1);
}

int main()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}

