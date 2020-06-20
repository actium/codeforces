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

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::string>& m)
{
    const size_t n = m.size();

    size_t count = 0;
    for (size_t i = 2; i < n; ++i) {
        for (size_t j = 2; j < n; ++j) {
            if (m[i-2][j-2] == 'X' && m[i-2][j] == 'X' && m[i-1][j-1] == 'X' && m[i][j-2] == 'X' && m[i][j] == 'X')
                ++count;
        }
    }

    answer(count);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> m(n);
    std::cin >> m;

    solve(m);

    return 0;
}

