#include <iostream>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer n, integer k)
{
    if (k == 1)
        return answer(n);

    const integer m = 1ull << 64 - __builtin_clzll(n);
    answer(m - 1);
}

int main()
{
    integer n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}

