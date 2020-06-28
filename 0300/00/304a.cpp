#include <iostream>

#include <cmath>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    size_t count = 0;
    for (unsigned c = 1; c <= n; ++c) {
        for (unsigned a = 1; a < c; ++a) {
            const unsigned b = sqrt(c * c - a * a);
            count += (a * a + b * b == c * c);
        }
    }

    answer(count / 2);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

