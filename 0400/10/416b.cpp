#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& t)
{
    const size_t m = t.size(), n = t[0].size();

    std::vector<unsigned> u(n), r(m);
    for (size_t i = 0; i < m; ++i) {
        u[0] += t[i][0];

        for (size_t j = 1; j < n; ++j)
            u[j] = std::max(u[j], u[j-1]) + t[i][j];

        r[i] = u.back();
    }

    answer(r);
}

int main()
{
    size_t m, n;
    std::cin >> m >> n;

    std::vector<std::vector<unsigned>> t(m, std::vector<unsigned>(n));
    std::cin >> t;

    solve(t);

    return 0;
}

