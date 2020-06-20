#include <iostream>
#include <vector>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    size_t x = 0;
    for (size_t i = 1; i < n; ++i)
        x += a[i];

    answer(1ull * n * (n + 1) / 2 - x);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    for (size_t i = 1; i < n; ++i)
        std::cin >> a[i];

    solve(a);

    return 0;
}

