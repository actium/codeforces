#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t n)
{
    size_t count = 0;
    for (size_t i = 1; i <= n / 2; ++i) {
        if ((n - i) % i == 0)
            ++count;
    }

    answer(count);
}

int main()
{
    size_t n;
    std::cin >> n;

    solve(n);

    return 0;
}

