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
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

bool check(const std::vector<std::string>& b, size_t r, size_t c, unsigned s, std::vector<std::vector<unsigned>>& t)
{
    if (t[r][c] != 0)
        return int(s - t[r][c]) >= 3;

    t[r][c] = ++s;

    if (r > 0 && b[r-1][c] == b[r][c] && check(b, r-1, c, s, t))
        return true;

    if (r + 1 < b.size() && b[r+1][c] == b[r][c] && check(b, r+1, c, s, t))
        return true;

    if (c > 0 && b[r][c-1] == b[r][c] && check(b, r, c-1, s, t))
        return true;

    if (c + 1 < b[0].size() && b[r][c+1] == b[r][c] && check(b, r, c+1, s, t))
        return true;

    return false;
}

void solve(const std::vector<std::string>& b)
{
    const size_t n = b.size(), m = b[0].length();

    std::vector<std::vector<unsigned>> t(n, std::vector<unsigned>(m));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (t[i][j] == 0 && check(b, i, j, 0, t))
                return answer(true);
        }
    }

    answer(false);
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
