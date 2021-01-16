#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned k, unsigned p)
{
    using integer = unsigned long long;

    const auto zcy = [](unsigned x) {
        integer a = x, b = 0;
        while (x != 0) {
            a *= 10;
            b = b * 10 + x % 10;
            x /= 10;
        }
        return a + b;
    };

    integer s = 0;
    for (unsigned i = 1; i <= k; ++i)
        s = (s + zcy(i)) % p;

    answer(s);
}

int main()
{
    unsigned k, p;
    std::cin >> k >> p;

    solve(k, p);

    return 0;
}

