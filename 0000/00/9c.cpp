#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    unsigned k = 0;
    for (unsigned x = 1; x <= (1 << 9); ++x) {
        unsigned y = 0;
        for (size_t i = 10; i-- > 0; ) {
            y *= 10;
            y += (x & 1 << i) != 0;
        }
        k += (y <= n);
    }

    answer(k);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

