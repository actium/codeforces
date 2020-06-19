#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
#if false
    size_t count = 1;
    for (size_t i = 0; i < n; ++i)
        count += 4 * i;

    answer(count);
#else
    answer(1 + 2 * n * (n - 1));
#endif
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

