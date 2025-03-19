#include <iostream>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned m)
{
    std::vector<unsigned> da(1+n+1);
    da[1] = 1;
    for (unsigned i = 1; i <= n; ++i) {
        if (i > 2)
            da[i] = (da[i] + da[i-1]) % m;

        da[i+1] = (da[i+1] + da[i]) % m;

        for (unsigned j = 2; i * j <= n; ++j) {
            const unsigned lb = i * j, ub = std::min(lb + j, n + 1);
            da[lb] = (da[lb] + da[i]) % m;
            da[ub] = (da[ub] + m - da[i]) % m;
        }
    }

    answer(da[n]);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}
