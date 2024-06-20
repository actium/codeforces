#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned a, unsigned b, unsigned c)
{
    unsigned v[21] = { a, b };
    for (size_t i = 2; i < 21; ++i)
        v[i] = v[i-1] + v[i-2];

    answer(v[c]);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned a, b, c;
    std::cin >> a >> b >> c;

    solve(a, b, c);

    return 0;
}
