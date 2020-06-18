#include <algorithm>
#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t d1, size_t d2, size_t d3)
{
    const size_t s1 = d1 + d2 + d3;
    const size_t s2 = 2 * (d1 + d2);
    const size_t s3 = 2 * (d1 + d3);
    const size_t s4 = 2 * (d2 + d3);

    answer(std::min({ s1, s2, s3, s4 }));
}

int main()
{
    size_t d1, d2, d3;
    std::cin >> d1 >> d2 >> d3;

    solve(d1, d2, d3);

    return 0;
}

