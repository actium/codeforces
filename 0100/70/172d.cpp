#include <iostream>
#include <vector>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned a, unsigned n)
{
    const unsigned ub = a + n;

    std::vector<unsigned> t(ub);
    for (unsigned i = 1; i * i < ub; ++i) {
        const unsigned d = i * i;

        for (unsigned j = d; j < ub; j += d)
            t[j] = d;
    }

    integer p = 0;
    for (unsigned x = a; x < ub; ++x)
        p += x / t[x];

    answer(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned a, n;
    std::cin >> a >> n;

    solve(a, n);

    return 0;
}
