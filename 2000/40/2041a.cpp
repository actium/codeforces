#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned a, unsigned b, unsigned c, unsigned d)
{
    bool v[6] = {};
    v[a] = true;
    v[b] = true;
    v[c] = true;
    v[d] = true;

    unsigned x = 1;
    while (v[x])
        ++x;

    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned a, b, c, d;
    std::cin >> a >> b >> c >> d;

    solve(a, b, c, d);

    return 0;
}
