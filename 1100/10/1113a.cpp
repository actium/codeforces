#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t n, size_t v)
{
    size_t s = 0;
    for (size_t x = 1, k = 0; x < n; --k, ++x) {
        const size_t d = std::min(n - x, v) - k;
        s += d * x, k += d;
    }

    answer(s);
}

int main()
{
    size_t n, v;
    std::cin >> n >> v;

    solve(n, v);

    return 0;
}

