#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned c, unsigned v0, unsigned v1, unsigned a, unsigned l)
{
    unsigned k = 0;
    for (unsigned r = 0; r < c; ) {
        unsigned d = std::min(v0 + k * a, v1);
        if (k > 0)
            d -= l;

        r += std::min(d, c - r);
        ++k;
    }

    answer(k);
}

int main()
{
    unsigned c, v0, v1, a, l;
    std::cin >> c >> v0 >> v1 >> a >> l;

    solve(c, v0, v1, a, l);

    return 0;
}

