#include <iostream>

using integer = unsigned long long;

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(integer n)
{
    constexpr unsigned M = 1000000007;

    if (n == 0)
        return answer(1);

    const auto raise = [](integer p) {
        integer v = 1;
        for (integer b = 2; p != 0; p /= 2) {
            if (p & 1)
                v = v * b % M;

            b = b * b % M;
        }
        return v;
    };

    answer(raise(n-1) * (1 + raise(n)) % M);
}

int main()
{
    integer n;
    std::cin >> n;

    solve(n);

    return 0;
}

