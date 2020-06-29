#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t n, size_t m)
{
    size_t k = 0;
    while (n > 0) {
        ++k;
        --n;
        if (k % m == 0)
            ++n;
    }

    answer(k);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}

