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

unsigned count(const std::vector<std::string>& s, size_t i, size_t j)
{
    const size_t n = s.size();
    const size_t m = s.front().size();

    const auto k = [&](size_t i, size_t j) {
        return i < n && j < m && s[i][j] == '*';
    };

    return k(i-1, j) + k(i-1, j+1) + k(i, j+1) + k(i+1, j+1) + k(i+1, j) + k(i+1, j-1) + k(i, j-1) + k(i-1, j-1);
}

bool check(const std::vector<std::string>& s, size_t i, size_t j)
{
    if (s[i][j] == '.')
        return count(s, i, j) == 0;

    if (s[i][j] > '0' && s[i][j] < '9')
        return count(s, i, j) == (s[i][j] - '0');

    return true;
}

void solve(size_t n, size_t m, const std::vector<std::string>& s)
{
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (!check(s, i, j))
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

    solve(n, m, s);

    return 0;
}

