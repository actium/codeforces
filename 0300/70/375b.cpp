#include <algorithm>
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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::string>& a)
{
    const size_t n = a.size(), m = a[0].size();

    std::vector<std::vector<unsigned>> c(m+1, std::vector<unsigned>(n));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = m; j > 0; --j) {
            if (a[i][j-1] == '1')
                c[j-1][i] = c[j][i] + 1;
        }
    }

    unsigned v = 0;
    for (size_t j = 0; j < m; ++j) {
        std::sort(c[j].begin(), c[j].end());

        for (size_t i = 0; i < n; ++i)
            v = std::max<unsigned>(v, c[j][i] * (n - i));
    }

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
