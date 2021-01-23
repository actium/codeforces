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

void answer(size_t x, size_t y)
{
    std::cout << 1+x << ' ' << 1+y << '\n';
}

void solve(const std::vector<std::string>& b, size_t k)
{
    const size_t n = b.size();

    std::vector<std::vector<unsigned>> f(n, std::vector<unsigned>(n));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0, c = 0, r = 0; j < n; ++j) {
            if (b[i][j] == '#') {
                c = 0;
            } else if (++c >= k) {
                for (size_t q = 0; q < k; ++q)
                    ++f[i][j-q];
            }

            if (b[j][i] == '#') {
                r = 0;
            } else if (++r >= k) {
                for (size_t q = 0; q < k; ++q)
                    ++f[j-q][i];
            }
        }
    }

    size_t r = 0, c = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (f[i][j] > f[r][c])
                r = i, c = j;
        }
    }

    answer(r, c);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<std::string> b(n);
    std::cin >> b;

    solve(b, k);

    return 0;
}

