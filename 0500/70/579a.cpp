#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned x)
{
#if false
    answer(__builtin_popcount(x));
#else
    unsigned k = 0;
    while (x != 0) {
        ++k;
        x &= x - 1;
    }

    answer(k);
#endif
}

int main()
{
    unsigned x;
    std::cin >> x;

    solve(x);

    return 0;
}

