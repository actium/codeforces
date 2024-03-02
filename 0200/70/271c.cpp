#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(size_t n, size_t k)
{
    if (n / k < 3)
        return no_answer();

    std::vector<unsigned> x(n);
    for (size_t i = 0; i < n; ++i)
        x[i] = 1 + i % k;

    for (size_t i = 0; i < k; ++i)
        x[i] = 1 + x[i] % k;

    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}
