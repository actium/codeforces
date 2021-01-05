#include <iostream>
#include <set>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer n)
{
    std::set<integer> d;
    for (integer x = 2; x * x <= n; ++x) {
        if (n % x == 0)
            for (d.insert(x); n % x == 0; n /= x);
    }

    for (const integer x : d)
        n *= x;

    answer(n);
}

int main()
{
    integer n;
    std::cin >> n;

    solve(n);

    return 0;
}

