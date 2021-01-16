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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(std::vector<std::string>& s)
{
    const size_t n = s.size(), m = s[0].length();

    const auto w = [&s](size_t r, size_t c) {
        for (size_t d = 0; d < 2; ++d) {
            if (s[r+d][c] == '.' || s[r+2][c+d] == '.' || s[r+2-d][c+2] == '.' || s[r][c+2-d] == '.')
                return;
        }
        for (size_t d = 0; d < 2; ++d)
            s[r+d][c] = s[r+2][c+d] = s[r+2-d][c+2] = s[r][c+2-d] = '*';
    };

    for (size_t i = 2; i < n; ++i) {
        for (size_t j = 2; j < m; ++j)
            w(i-2, j-2);
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (s[i][j] == '#')
                return answer(false);
        }
    }

    answer(true);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}

