#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Operation {
    unsigned x[3];
    unsigned y[3];

    Operation(size_t x1, size_t y1, size_t x2, size_t y2, size_t x3, size_t y3)
    {
        x[0] = 1 + x1;
        y[0] = 1 + y1;
        x[1] = 1 + x2;
        y[1] = 1 + y2;
        x[2] = 1 + x3;
        y[2] = 1 + y3;
    }
};

void answer(const std::vector<Operation>& v)
{
    std::cout << v.size() << '\n';

    for (const auto& o : v) {
        std::cout << o.x[0] << ' ' << o.y[0] << ' ';
        std::cout << o.x[1] << ' ' << o.y[1] << ' ';
        std::cout << o.x[2] << ' ' << o.y[2] << '\n';
    }
}

void solve(std::vector<std::string>& g)
{
    const size_t n = g.size(), m = g[0].size();

    std::vector<Operation> q;

    const auto flip = [&](size_t x1, size_t y1, size_t x2, size_t y2, size_t x3, size_t y3) {
        q.emplace_back(x1, y1, x2, y2, x3, y3);

        g[x1][y1] ^= 1;
        g[x2][y2] ^= 1;
        g[x3][y3] ^= 1;
    };

    for (size_t i = 1; i < n-1; ++i) {
        for (size_t j = 0; j < m-1; ++j) {
            if (g[i-1][j] != '0') {
                const unsigned d = (g[i-1][j+1] == '1');
                flip(i-1, j, i, j, i-d, j+1);
            }
        }

        if (g[i-1][m-1] == '1')
            flip(i-1, m-1, i, m-2, i, m-1);
    }

    for (size_t j = 0; j < m-1; ++j) {
        if (g[n-2][j] == '0' && g[n-1][j] == '0')
            continue;

        if (g[n-2][j] == '1' && g[n-1][j] == '1') {
            flip(n-2, j, n-1, j, n-2, j+1);
            continue;
        }

        const unsigned d = (g[n-2][j] == '1') + 1;
        flip(n-d, j, n-2, j+1, n-1, j+1);
    }

    while (g[n-2][m-2] != '0' || g[n-2][m-1] != '0' || g[n-1][m-2] != '0' || g[n-1][m-1] != '0') {
        const unsigned x = (g[n-2][m-2] - '0') << 3 | (g[n-2][m-1] - '0') << 2 | (g[n-1][m-2] - '0') << 1 | (g[n-1][m-1] - '0');
        switch (x) {
            // 01  xx  10
            // 00  x   10
            case 4: flip(n-2, m-2, n-2, m-1, n-1, m-2); break;

            // 00  x   10
            // 01  xx  10
            case 1: flip(n-2, m-2, n-1, m-2, n-1, m-1); break;

            // 00   x  01
            // 10  xx  01
            case 2: flip(n-2, m-1, n-1, m-2, n-1, m-1); break;

            // 10  xx  01
            // 00   x  01
            case 8: flip(n-2, m-2, n-2, m-1, n-1, m-1); break;

            // 01  xx  10
            // 01  x   11
            case 5: flip(n-2, m-2, n-2, m-1, n-1, m-2); break;

            // 00  xx  11
            // 11  x   01
            case 3: flip(n-2, m-2, n-2, m-1, n-1, m-2); break;

            // 11  x   01
            // 00  xx  11
            case 12: flip(n-2, m-2, n-1, m-2, n-1, m-1); break;

            // 10  xx  01
            // 10   x  11
            case 10: flip(n-2, m-2, n-2, m-1, n-1, m-1); break;

            // 10  xx  01
            // 01  x   11
            case 9: flip(n-2, m-2, n-2, m-1, n-1, m-2); break;

            // 01  xx  10
            // 10   x  11
            case 6: flip(n-2, m-2, n-2, m-1, n-1, m-1); break;

            // 11  xx  00
            // 01   x  00
            case 13: flip(n-2, m-2, n-2, m-1, n-1, m-1); break;

            // 11  xx  00
            // 10  x   00
            case 14: flip(n-2, m-2, n-2, m-1, n-1, m-2); break;

            // 01   x  00
            // 11  xx  00
            case 7: flip(n-2, m-1, n-1, m-2, n-1, m-1); break;

            // 10  x   00
            // 11  xx  00
            case 11: flip(n-2, m-2, n-1, m-2, n-1, m-1); break;

            // 11  xx  00
            // 11  x   01
            case 15: flip(n-2, m-2, n-2, m-1, n-1, m-2); break;
        }
    }

    answer(q);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> g(n);
    std::cin >> g;

    solve(g);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
