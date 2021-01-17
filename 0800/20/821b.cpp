#include <iostream>

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(unsigned m, unsigned b)
{
    const auto s = [](unsigned n) {
        return n * (n + 1ull) / 2;
    };

    unsigned long long k = 0;
    for (unsigned y = 0; y <= b; ++y) {
        const unsigned x = m * (b - y);

        k = std::max(k, s(y) * (x + 1) + s(x) * (y + 1));
    }

    answer(k);
}

int main()
{
    unsigned m, b;
    std::cin >> m >> b;

    solve(m, b);

    return 0;
}

