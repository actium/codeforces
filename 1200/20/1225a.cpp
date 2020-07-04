#include <iostream>

void answer(int v)
{
    std::cout << v << '\n';
}

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned a, unsigned b)
{
    if (a == 9 && b == 1)
        return answer(99, 100);

    if (a + 1 < b || a > b)
        return answer(-1);
 
    if (a == b)
        answer(a * 10, a * 10 + 1);
    else
        answer(a * 10 + 9, b * 10);
}

int main()
{
    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}

