#include <algorithm>
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

void answer(unsigned u, const std::vector<std::string>& v)
{
    std::cout << u << '\n';

    for (const std::string& x : v)
        std::cout << x << '\n';
}

unsigned paint(std::vector<std::string>& b, size_t r, size_t c, char x)
{
    const size_t n = b.size(), m = b[0].size();

    std::swap(b[r][c], x);

    unsigned k = 1;
    if (r > 0 && b[r-1][c] == x)
        k += paint(b, r-1, c, b[r][c]);
    if (r + 1 < n && b[r+1][c] == x)
        k += paint(b, r+1, c, b[r][c]);
    if (c > 0 && b[r][c-1] == x)
        k += paint(b, r, c-1, b[r][c]);
    if (c+1 < m && b[r][c+1] == x)
        k += paint(b, r, c+1, b[r][c]);

    return k;
}

struct Sea {
    size_t r;
    size_t c;
    unsigned v;
};

void solve(std::vector<std::string>& b, size_t k)
{
    const size_t n = b.size(), m = b[0].size();

    for (size_t i = 0; i < n; ++i) {
        if (b[i][0] == '.')
            paint(b, i, 0, '@');
        if (b[i][m-1] == '.')
            paint(b, i, m-1, '@');
    }
    for (size_t j = 0; j < m; ++j) {
        if (b[0][j] == '.')
            paint(b, 0, j, '@');
        if (b[n-1][j] == '.')
            paint(b, n-1, j, '@');
    }

    std::vector<Sea> s;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (b[i][j] == '.')
                s.push_back({ i, j, paint(b, i, j, '$') });
        }
    }

    std::sort(s.begin(), s.end(), [](const Sea& a, const Sea& b) {
        return a.v > b.v;
    });

    unsigned q = 0;
    while (s.size() > k) {
        q += paint(b, s.back().r, s.back().c, '*');
        s.pop_back();
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (b[i][j] == '$')
                b[i][j] = '.';

            if (b[i][j] == '@')
                b[i][j] = '.';
        }
    }

    answer(q, b);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::string> b(n);
    std::cin >> b;

    solve(b, k);

    return 0;
}
