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

bool check_adj_sheep(const std::vector<std::string>& f, size_t r, size_t c)
{
    const size_t n = f.size();
    const size_t m = f[r].size();

    return (r > 0 && f[r-1][c] == 'S')
        || (r < n-1 && f[r+1][c] == 'S')
        || (c > 0 && f[r][c-1] == 'S')
        || (c < m-1 && f[r][c+1] == 'S');
}

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void answer(const std::vector<std::string>& v)
{
    answer(true);

    for (const std::string& x : v)
        std::cout << x << '\n';
}

void solve(std::vector<std::string>& f, size_t m)
{
    const size_t n = f.size();

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (f[i][j] == 'W' && check_adj_sheep(f, i, j))
                return answer(false);

            if (f[i][j] == '.')
                f[i][j] = 'D';
        }
    }

    answer(f);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> f(n);
    std::cin >> f;

    solve(f, m);

    return 0;
}

