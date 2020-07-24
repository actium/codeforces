#include <iostream>

void solve(size_t n)
{
    constexpr char s[4] = { 'a', 'a', 'b', 'b' };

    for (size_t i = 0; i < n; ++i)
        std::cout << s[i % 4];

    std::cout << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    solve(n);

    return 0;
}

