#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& p)
{
    const size_t n = p[0].size(), m = p.size();

    std::vector<std::vector<size_t>> x(m, std::vector<size_t>(1+n));
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j)
            x[i][p[i][j]] = j;
    }

    const auto check = [&](size_t i) {
        for (size_t j = 1; j < m; ++j) {
            const size_t d = x[j][p[0][i]];
            if (d + 1 == n || p[j][d+1] != p[0][i+1])
                return false;
        }
        return true;
    };

    std::vector<unsigned> c(1+n, 1);
    for (size_t i = n-2; ~i != 0; --i) {
        if (check(i))
            c[p[0][i]] += c[p[0][i+1]];
    }

    integer k = 0;
    for (size_t i = 1; i <= n; ++i)
        k += c[i];

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> p(m, std::vector<unsigned>(n));
    std::cin >> p;

    solve(p);

    return 0;
}
