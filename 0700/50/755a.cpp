#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
#if false
    for (unsigned m = 1; m <= 1000; ++m) {
        const unsigned x = n * m + 1;
        for (unsigned i = 2; i * i < x; ++i) {
            if (x % i == 0)
                return answer(m);
        }
    }
#endif

    answer(n > 2 ? n - 2 : n + 2);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

