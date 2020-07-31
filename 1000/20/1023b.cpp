#include <iostream>

using integer = long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer n, integer k)
{
    if (n-1 + n < k)
        return answer(0);

    if (k <= n)
        return answer((k - 1) / 2);

    const integer x = k - n;
    const integer y = (n - x + 1) / 2;

    answer(y);
}

int main()
{
    integer n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}

