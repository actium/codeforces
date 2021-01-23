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

void solve(unsigned n, unsigned k, unsigned t)
{
    std::vector<unsigned> a(n);
    for (size_t i = 0; 100 * i <= n * t; ++i) {
        if (100 * (1 + i) <= n * t)
            a[i] = k;
        else
            a[i] = k * n * t / 100 - k * i;
    }

    answer(a);
}

int main()
{
    unsigned n, k, t;
    std::cin >> n >> k >> t;

    solve(n, k, t);

    return 0;
}

