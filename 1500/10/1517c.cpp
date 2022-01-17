#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void solve(const std::vector<unsigned>& p)
{
    const size_t n = p.size();

    std::vector<std::vector<unsigned>> b(n);
    for (size_t i = 0; i < n; ++i)
        b[i].resize(1 + i);

    for (size_t i = 0; i < n; ++i) {
        b[i][i] = p[i];

        size_t r = i, c = i;
        for (unsigned k = p[i]; k != 1; --k) {
            if (c < r && b[r-1][c] == 0) {
                b[--r][c] = p[i];
                continue;
            }
            if (c > 0 && b[r][c-1] == 0) {
                b[r][--c] = p[i];
                continue;
            }
            if (r < n && b[r+1][c] == 0) {
                b[++r][c] = p[i];
                continue;
            }
        }
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < i; ++j)
            std::cout << b[i][j] << ' ';

        std::cout << p[i] << '\n';
    }
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}
