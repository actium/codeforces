#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned a, unsigned b, unsigned m, unsigned r)
{
    unsigned v[m] = {};
    for (unsigned i = 1; ; ++i) {
        r = (a * r + b) % m;
        if (v[r] != 0)
            return answer(i - v[r]);

        v[r] = i;
    }
}

int main()
{
    unsigned a, b, m, r;
    std::cin >> a >> b >> m >> r;

    solve(a, b, m, r);

    return 0;
}

