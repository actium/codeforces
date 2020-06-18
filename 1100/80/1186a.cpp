#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(size_t n, size_t m, size_t k)
{
    answer(m >= n && k >= n);
}

int main()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    solve(n, m, k);

    return 0;
}

