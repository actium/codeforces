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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::string>& a)
{
    const size_t n = a.size(), m = a[0].length();

    std::vector<std::vector<unsigned>> ps(1+5000, std::vector<unsigned>(1+5000));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j)
            ps[1+i][1+j] = ps[i][1+j] + ps[1+i][j] - ps[i][j] + (a[i][j] - '0');
    }

    unsigned x = n * m;
    for (size_t k = 2; k <= std::max(n, m); ++k) {
        unsigned s = 0;
        for (size_t i = 0; i < n; i += k) {
            for (size_t j = 0; j < m; j += k) {
                const size_t r = std::min(i + k, n), c = std::min(j + k, m);

                const unsigned q = ps[r][c] - ps[r][j] - ps[i][c] + ps[i][j];
                s += std::min<unsigned>(q, k * k - q);
            }
        }

        x = std::min(x, s);
    }

    answer(x);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
