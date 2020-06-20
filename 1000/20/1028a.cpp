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
    std::cout << 1 + x << ' ' << 1 + y << '\n';
}

void solve(const std::vector<std::string>& s, size_t m)
{
    const size_t n = s.size();

    size_t min_r = n, max_r = 0;
    size_t min_c = m, max_c = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (s[i][j] == 'B') {
                min_r = std::min(min_r, i);
                max_r = std::max(max_r, i);
                min_c = std::min(min_c, j);
                max_c = std::max(max_c, j);
            }
        }
    }

    answer((min_r + max_r) / 2, (min_c + max_c) / 2);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s, m);

    return 0;
}


