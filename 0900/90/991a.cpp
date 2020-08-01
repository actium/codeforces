#include <iostream>

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(unsigned a, unsigned b, unsigned c, unsigned n)
{
    if (c > a || c > b)
        return answer(-1);

    const unsigned d = (a - c) + (b - c) + c;
    if (d + 1 > n)
        return answer(-1);

    answer(n - d);
}

int main()
{
    unsigned a, b, c, n;
    std::cin >> a >> b >> c >> n;

    solve(a, b, c, n);

    return 0;
}

