#include <iostream>

#include <cmath>

void answer(char v)
{
    std::cout << v << '\n';
}

void solve(unsigned x, unsigned y)
{
    const long double a = y * logl(x);
    const long double b = x * logl(y);

    if (a > b)
        return answer('>');

    if (a < b)
        return answer('<');

    answer('=');
}

int main()
{
    unsigned x, y;
    std::cin >> x >> y;

    solve(x, y);

    return 0;
}

