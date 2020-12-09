#include <iostream>

using integer = unsigned long long;

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer k)
{
    if (k > 36)
        return no_answer();

    integer n = k % 2 * 9;
    while (k > 1) {
        n = n * 10 + 8;
        k -= 2;
    }

    answer(n);
}

int main()
{
    integer k;
    std::cin >> k;

    solve(k);

    return 0;
}

