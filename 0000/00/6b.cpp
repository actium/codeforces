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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::string>& r, char c)
{
    const size_t n = r.size();
    const size_t m = r.front().size();

    unsigned k = 0;

    unsigned v[26] = {};
    const auto count = [&](char x) {
        if (x != '.' && x != c && v[x - 'A'] == 0)
            v[x - 'A'] = ++k;
    };

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (r[i][j] != c)
                continue;

            if (i > 0)
                count(r[i-1][j]);

            if (j > 0)
                count(r[i][j-1]);

            if (i+1 < n)
                count(r[i+1][j]);

            if (j+1 < m)
                count(r[i][j+1]);
        }
    }

    answer(k);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    char c;
    std::cin >> c;

    std::vector<std::string> r(n);
    std::cin >> r;

    solve(r, c);

    return 0;
}

