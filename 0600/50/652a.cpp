#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned h1, unsigned h2, unsigned a, unsigned b)
{
    h1 += 8 * a;

    if (h1 >= h2)
        return answer(0);

    if (b >= a)
        return no_answer();

    const unsigned p = 12 * (a - b);
    answer((h2 - h1 + p - 1) / p);
}

int main()
{
    unsigned h1, h2;
    std::cin >> h1 >> h2;

    unsigned a, b;
    std::cin >> a >> b;

    solve(h1, h2, a, b);

    return 0;
}
