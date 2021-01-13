#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "black", "white" };
    std::cout << s[v] << '\n';
}

void solve(int x, int y)
{
    const unsigned r = x * x + y * y;

    unsigned q = 0;
    while (q * q <= r)
        ++q;

    --q;

    if (q * q == r)
        return answer(0);

    q += (x * y < 0);

    answer(q % 2);
}

int main()
{
    int x, y;
    std::cin >> x >> y;

    solve(x, y);

    return 0;
}

