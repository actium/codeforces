#include <iostream>
#include <utility>

using integer = unsigned long long;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(integer n)
{
    unsigned k = 1;
    for (integer a = 2, b = 3; b <= n; ++k)
        a = std::exchange(b, a + b);

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
