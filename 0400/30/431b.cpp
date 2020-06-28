#include <algorithm>
#include <array>
#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const unsigned g[5][5])
{
    std::array<size_t, 5> q;
    for (size_t i = 0; i < 5; ++i)
        q[i] = i;

    size_t best = 0;
    do {
        const size_t score = g[q[0]][q[1]] + g[q[1]][q[0]] + 2 * (g[q[2]][q[3]] + g[q[3]][q[2]]) +
            g[q[1]][q[2]] + g[q[2]][q[1]] + 2 * (g[q[3]][q[4]] + g[q[4]][q[3]]);
        best = std::max(best, score);

    } while (std::next_permutation(q.begin(), q.end()));

    answer(best);
}

int main()
{
    unsigned g[5][5];

    for (size_t i = 0; i < 5; ++i) {
        for (size_t j = 0; j < 5; ++j) {
            std::cin >> g[i][j];
        }
    }

    solve(g);

    return 0;
}

