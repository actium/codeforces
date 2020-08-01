#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned x)
{
    constexpr unsigned t[6][3] = {
        { 0, 1, 2 }, { 1, 0, 2 },
        { 1, 2, 0 }, { 2, 1, 0 },
        { 2, 0, 1 }, { 0, 2, 1 },
    };

    answer(t[n % 6][x]);
}

int main()
{
    unsigned n;
    std::cin >> n;

    unsigned x;
    std::cin >> x;

    solve(n, x);

    return 0;
}

