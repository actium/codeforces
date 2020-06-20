#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t a, size_t b, size_t c)
{
    const size_t d = std::min(a, b);
    a -= d, b -= d;

    answer((b > 0) + (c + d) * 2 + (a > 0));
}

int main()
{
    size_t a, b, c;
    std::cin >> a >> b >> c;

    solve(a, b, c);

    return 0;
}

