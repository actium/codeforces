#include <iostream>

constexpr unsigned m = 1 << 30;

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned a, unsigned b, unsigned c)
{
    unsigned d[1000000] = {};
    for (size_t i = 1; i <= 1000000; ++i) {
        for (size_t j = i; j <= 1000000; j += i) {
            ++d[j-1];
        }
    }

    unsigned long long s = 0;
    for (unsigned i = 1; i <= a; ++i) {
        for (unsigned j = 1; j <= b; ++j) {
            for (unsigned k = 1; k <= c; ++k)
                s += d[i * j * k - 1];
        }
    }

    answer(s % m);
}

int main()
{
    unsigned a, b, c;
    std::cin >> a >> b >> c;

    solve(a, b, c);

    return 0;
}

