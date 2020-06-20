#include <algorithm>
#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f)
{
    size_t c1 = 0;
    {
        const size_t k = std::min({ a, d });
        c1 = k * e + std::min({ b, c, d - k }) * f;
    }

    size_t c2 = 0;
    {
        const size_t k = std::min({ b, c, d });
        c2 = k * f + std::min({ a, d - k }) * e;
    }

    answer(std::max(c1, c2));
}

int main()
{
    size_t a;
    std::cin >> a;

    size_t b;
    std::cin >> b;

    size_t c;
    std::cin >> c;

    size_t d;
    std::cin >> d;

    size_t e;
    std::cin >> e;

    size_t f;
    std::cin >> f;

    solve(a, b, c, d, e, f);

    return 0;
}

