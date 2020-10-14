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

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(size_t n, size_t m, const std::vector<std::string>& a)
{
    const auto count = [&](size_t i, size_t j) {
        unsigned c = 0;

        for (size_t k = 0; k < n; ++k)
            c += (a[k][j] == a[i][j]);

        for (size_t k = 0; k < m; ++k)
            c += (a[i][k] == a[i][j]);

        return c;
    };

    std::string s;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (count(i, j) == 2)
                s.push_back(a[i][j]);
        }
    }

    answer(s);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    std::cin >> a;

    solve(n, m, a);

    return 0;
}

