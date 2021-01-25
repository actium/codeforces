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

void answer(unsigned x, const std::vector<std::string>& y)
{
    std::cout << x << '\n';

    for (const std::string& r : y)
        std::cout << r << '\n';
}

void solve(std::vector<std::string>& s, size_t k)
{
    using seat_t = std::pair<size_t, size_t>;

    const size_t n = s.size(), m = s[0].length();

    std::vector<std::pair<unsigned, seat_t>> p;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (s[i][j] == '.') {
                p.emplace_back(0, std::make_pair(i, j));
                p.back().first += (j > 0 && s[i][j-1] == 'S');
                p.back().first += (j+1 < m && s[i][j+1] == 'S');
            }
        }
    }

    std::sort(p.begin(), p.end());

    for (size_t i = 0; i < k; ++i)
        s[p[i].second.first][p[i].second.second] = 'x';

    unsigned c = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (s[i][j] != '.' && s[i][j] != '-') {
                c += (j > 0 && s[i][j-1] == 'S');
                c += (j+1 < m && s[i][j+1] == 'S');
            }
        }
    }

    answer(c, s);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s, k);

    return 0;
}

