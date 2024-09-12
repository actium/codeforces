#include <iostream>

constexpr unsigned t[13] = { 10, 10, 8, 9, 8, 7, 7, 7, 7, 0, 9, 6, 8 };

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    answer(t[n]);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
