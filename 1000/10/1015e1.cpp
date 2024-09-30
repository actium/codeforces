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

struct Star {
    unsigned r;
    unsigned c;
    unsigned k;
};

void answer(const std::vector<Star>& v)
{
    std::cout << v.size() << '\n';
    for (const Star& x : v)
        std::cout << x.r << ' ' << x.c << ' ' << x.k << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::vector<std::string>& b)
{
    const size_t n = b.size(), m = b[0].size();

    const auto check = [&](size_t r, size_t c) {
        if (b[r][c] == '.')
            return 0u;

        unsigned k = 1;
        while (k <= r && k <= c && r + k < n && c + k < m && b[r-k][c] != '.' && b[r][c+k] != '.' && b[r+k][c] != '.' && b[r][c-k] != '.') {
            b[r-k][c] = '@';
            b[r][c+k] = '@';
            b[r+k][c] = '@';
            b[r][c-k] = '@';

            ++k;
        }
        return k;
    };

    std::vector<Star> q;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            const unsigned k = check(i, j);
            if (k > 1) {
                b[i][j] = '@';
                q.push_back({ 1+i, 1+j, k-1 });
            }
        }
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (b[i][j] == '*')
                return no_answer();
        }
    }

    answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> b(n);
    std::cin >> b;

    solve(b);

    return 0;
}
