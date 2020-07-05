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

bool best(const std::vector<std::string>& s, size_t i, size_t j)
{
    const size_t n = s.size();

    for (size_t k = 0; k < n; ++k) {
        if (s[k][j] > s[i][j])
            return false;
    }
    return true;
}

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::string>& s, size_t m)
{
    const size_t n = s.size();

    size_t c = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (best(s, i, j)) {
                ++c;
                break;
            }
        }
    }

    answer(c);
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

