#include <iostream>

void solve(size_t n)
{
    constexpr const char p[4] = { 'a', 'b', 'c', 'd' };

    for (size_t i = 0; i < n; ++i)
        std::cout << p[i % 4];

    std::cout << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    solve(n);

    return 0;
}

