#include <iostream>

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(size_t f0, size_t f5)
{
    if (f0 == 0)
        return answer(-1);

    for (size_t i = 0; i < f5 / 9; ++i)
        std::cout << "555555555";

    if (f5 < 9)
        f0 = 1;

    for (size_t i = 0; i < f0; ++i)
        std::cout << '0';

    std::cout << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    size_t f0 = 0, f5 = 0;
    for (size_t i = 0; i < n; ++i) {
        unsigned a;
        std::cin >> a;

        f0 += (a == 0);
        f5 += (a == 5);
    }

    solve(f0, f5);

    return 0;
}

