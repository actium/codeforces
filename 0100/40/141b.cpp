#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(int x, int y, unsigned a)
{
    if (y % a == 0)
        return no_answer();

    const unsigned r = y / a;
    if (r == 0 && abs(2 * x) < a)
        return answer(1);

    if (r % 2 == 1 && abs(2 * x) < a)
        return answer(r / 2 * 3 + 2);

    if (r != 0 && r % 2 == 0 && x != 0 && abs(x) < a)
        return answer(r / 2 * 3 + (x > 0));

    no_answer();
}

int main()
{
    unsigned a;
    std::cin >> a;

    int x, y;
    std::cin >> x >> y;

    solve(x, y, a);

    return 0;
}
