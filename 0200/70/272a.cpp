#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t n, size_t k)
{
    size_t count = 0;
    for (size_t i = 1; i <= 5; ++i) {
        if ((k + i - 1) % (n + 1) != 0)
            ++count;
    }

    answer(count);
}

int main()
{
    size_t n;
    std::cin >> n;

    size_t k = 0;
    for (size_t i = 0; i < n; ++i) {
        size_t count;
        std::cin >> count;

        k += count;
    }

    solve(n, k);

    return 0;
}

