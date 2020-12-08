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

void solve(size_t n, size_t k)
{
    std::vector<unsigned> p(n);

    for (size_t i = 0; i < k; i += 2)
        p[i] = 1 + i / 2;

    for (size_t i = 1; i < k; i += 2)
        p[i] = n - i / 2;

    if (k % 2 == 0) {
        for (size_t i = k; i < n; ++i)
            p[i] = n - (i - k / 2);
    } else {
        for (size_t i = k; i < n; ++i)
            p[i] = 1 + (i - k / 2);
    }

    answer(p);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}

