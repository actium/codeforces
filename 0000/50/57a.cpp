#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned x1, unsigned y1, unsigned x2, unsigned y2)
{
    if (x1 == x2 && (x1 == 0 || x1 == n))
        return answer(abs(y1 - y2));

    if (y1 == y2 && (y1 == 0 || y1 == n))
        return answer(abs(x1 - x2));

    unsigned d = ~0u;
    d = std::min(d, x1 + y1 + x2 + y2);
    d = std::min(d, n - x1 + y1 + n - x2 + y2);
    d = std::min(d, n - x1 + n - y1 + n - x2 + n - y2);
    d = std::min(d, x1 + n - y1 + x2 + n - y2);

    answer(d);
}

int main()
{
    unsigned n, x1, y1, x2, y2;
    std::cin >> n >> x1 >> y1 >> x2 >> y2;

    solve(n, x1, y1, x2, y2);

    return 0;
}

