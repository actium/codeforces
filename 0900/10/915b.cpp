#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned x, unsigned a, unsigned b)
{
    if (a == 1 && b == n)
        return answer(0);

    if (a == 1)
        return answer(abs(b - x) + 1);

    if (b == n)
        return answer(abs(a - x) + 1);

    answer(std::min(abs(a - x), abs(b - x)) + 1 + b - a + 1);
}

int main()
{
    unsigned n, x, a, b;
    std::cin >> n >> x >> a >> b;

    solve(n, x, a, b);

    return 0;
}

