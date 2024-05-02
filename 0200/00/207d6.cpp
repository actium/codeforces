#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    constexpr unsigned t[] = {
        1, 1, 2, 2, 3, 3,
        3, 1, 2, 2, 1, 3,
        3, 3, 3, 3, 3,
        1, 1, 1, 1, 1,
        2, 2, 2,
        1, 3, 1, 3, 1, 3,
        2, 2, 2, 3, 3,
        1, 2, 1, 2, 1, 2,
        1, 1, 2, 2, 3, 3,
        3, 3, 3, 2, 2, 2, 1, 1, 1,
     };

    answer(t[n / 1000]);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
