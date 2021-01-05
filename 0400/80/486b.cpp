#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::vector<unsigned>>& v)
{
    std::cout << "YES" << '\n';

    for (const std::vector<unsigned>& r : v) {
        const char* separator = "";
        for (const unsigned x : r) {
            std::cout << separator << x;
            separator = " ";
        }
        std::cout << '\n';
    }
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& b)
{
    const size_t n = b.size(), m = b[0].size();

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(m, 1));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (b[i][j] == 1)
                continue;

            for (size_t k = 0; k < n; ++k)
                a[k][j] = 0;

            for (size_t k = 0; k < m; ++k)
                a[i][k] = 0;
        }
    }

    std::vector<std::vector<unsigned>> c(n, std::vector<unsigned>(m, 0));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (a[i][j] == 0)
                continue;

            for (size_t k = 0; k < n; ++k)
                c[k][j] = 1;

            for (size_t k = 0; k < m; ++k)
                c[i][k] = 1;
        }
    }

    if (c == b)
        return answer(a);

    no_answer();
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> b(n, std::vector<unsigned>(m));
    std::cin >> b;

    solve(b);

    return 0;
}

