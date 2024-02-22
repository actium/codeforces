#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(integer n)
{
    integer k = n;

    for (const unsigned x : { 2, 3, 5, 7, 30, 42, 70, 105 })
        k -= n / x;

    for (const unsigned x : { 6, 10, 14, 15, 21, 35, 210 })
        k += n / x;

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    integer n;
    std::cin >> n;

    solve(n);

    return 0;
}
