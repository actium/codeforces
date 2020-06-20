#include <algorithm>
#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned a, unsigned b, unsigned c)
{
    answer(std::max({ a + b + c, (a + b) * c, a * (b + c), a * b * c }));
}

int main()
{
    unsigned a, b, c;
    std::cin >> a >> b >> c;

    solve(a, b, c);

    return 0;
}

