#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& a)
{
    const size_t n = a.size(), m = a[0].size();

    std::vector<std::vector<unsigned>> t[8];
    for (size_t i = 0; i < 8; ++i)
        t[i].resize(n, std::vector<unsigned>(m));

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (i != 0) {
                t[0][i][j] = std::max(t[0][i][j], t[0][i-1][j] + a[i-1][j]);
                t[0][i][j] = std::max(t[0][i][j], t[4][i-1][j] + a[i-1][j]);

                t[1][i][m-1-j] = std::max(t[1][i][m-1-j], t[1][i-1][m-1-j] + a[i-1][m-1-j]);
                t[1][i][m-1-j] = std::max(t[1][i][m-1-j], t[6][i-1][m-1-j] + a[i-1][m-1-j]);

                t[2][n-1-i][j] = std::max(t[2][n-1-i][j], t[2][n-i][j] + a[n-i][j]);
                t[2][n-1-i][j] = std::max(t[2][n-1-i][j], t[5][n-i][j] + a[n-i][j]);

                t[3][n-1-i][m-1-j] = std::max(t[3][n-1-i][m-1-j], t[3][n-i][m-1-j] + a[n-i][m-1-j]);
                t[3][n-1-i][m-1-j] = std::max(t[3][n-1-i][m-1-j], t[7][n-i][m-1-j] + a[n-i][m-1-j]);
            }
            if (j != 0) {
                t[4][i][j] = std::max(t[4][i][j], t[0][i][j-1] + a[i][j-1]);
                t[4][i][j] = std::max(t[4][i][j], t[4][i][j-1] + a[i][j-1]);

                t[5][n-1-i][j] = std::max(t[5][n-1-i][j], t[2][n-1-i][j-1] + a[n-1-i][j-1]);
                t[5][n-1-i][j] = std::max(t[5][n-1-i][j], t[5][n-1-i][j-1] + a[n-1-i][j-1]);

                t[6][i][m-1-j] = std::max(t[6][i][m-1-j], t[1][i][m-j] + a[i][m-j]);
                t[6][i][m-1-j] = std::max(t[6][i][m-1-j], t[6][i][m-j] + a[i][m-j]);

                t[7][n-1-i][m-1-j] = std::max(t[7][n-1-i][m-1-j], t[3][n-1-i][m-j] + a[n-1-i][m-j]);
                t[7][n-1-i][m-1-j] = std::max(t[7][n-1-i][m-1-j], t[7][n-1-i][m-j] + a[n-1-i][m-j]);
            }
        }
    }

    unsigned v = 0;
    for (size_t i = 1; i + 1 < n; ++i) {
        for (size_t j = 1; j + 1 < m; ++j) {
            v = std::max(v, t[0][i][j] + t[3][i][j] + t[5][i][j] + t[6][i][j]);
            v = std::max(v, t[4][i][j] + t[2][i][j] + t[7][i][j] + t[1][i][j]);
        }
    }

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(m));
    std::cin >> a;

    solve(a);

    return 0;
}
