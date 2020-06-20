#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t k, size_t n, size_t s, size_t p)
{
    const size_t a = (n + s - 1) / s;
    const size_t b = k * a;
    const size_t c = (b + p - 1) / p;

    answer(c);
}

int main()
{
    size_t k, n, s, p;
    std::cin >> k >> n >> s >> p;

    solve(k, n, s, p);

    return 0;
}

