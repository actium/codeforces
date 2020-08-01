#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned a, unsigned b)
{
    constexpr unsigned t[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

    unsigned k = 0;
    for (unsigned i = a; i <= b; ++i) {
        for (unsigned n = i; n != 0; n /= 10)
            k += t[n % 10];
    }

    answer(k);
}

int main()
{
    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}

