#include <iostream>

#include <cmath>

void answer(size_t x, size_t y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(size_t n)
{
    for (size_t a = sqrt(n); a > 0; --a) {
        const size_t b = n / a;
        if (a * b == n)
            return answer(a, b);
    }
}

int main()
{
    size_t n;
    std::cin >> n;

    solve(n);

    return 0;
}

