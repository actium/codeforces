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

void solve(const std::vector<std::string>& p)
{
    const size_t n = p.size(), m = p[0].length();

    size_t b[4] = { ~0u, 0, ~0u, 0 };
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (p[i][j] == '.')
                continue;

            b[0] = std::min(b[0], i);
            b[1] = std::max(b[1], i);
            b[2] = std::min(b[2], j);
            b[3] = std::max(b[3], j);
        }
    }

    for (size_t i = b[0]; i <= b[1]; ++i) {
        for (size_t j = b[2]; j <= b[3]; ++j) {
            if (p[i][j] != 'X')
                return answer(false);
        }
    }

    answer(true);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}
