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

bool tile(char& cell)
{
    if (cell == '#')
        return false;

    cell = '#';
    return true;
}

bool tile(std::vector<std::string>& b, size_t i, size_t j)
{
    const size_t n = b.size();

    return i > 0 && i < n-1 && j > 0 && j < n-1
        && tile(b[i-1][j]) && tile(b[i][j-1]) && tile(b[i][j]) && tile(b[i][j+1]) && tile(b[i+1][j]);
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(std::vector<std::string>& b)
{
    const size_t n = b.size();

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (b[i][j] == '.' && !tile(b, i+1, j))
                return answer(false);
        }
    }

    answer(true);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> b(n);
    std::cin >> b;

    solve(b);

    return 0;
}

