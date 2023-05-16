#include <algorithm>
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

integer count(std::vector<unsigned>& v)
{
    const size_t n = v.size();

    std::sort(v.begin(), v.end());

    integer s = 0, t = 0;
    for (size_t i = 1; i < n; ++i) {
        t += v[i-1];
        s += integer(v[i]) * i - t;
    }
    return s;
}

void solve(const std::vector<std::vector<unsigned>>& c)
{
    const size_t n = c.size(), m = c[0].size();

    integer s = 0;
    for (size_t i = 0; i < m; ++i) {
        std::vector<unsigned> u(n);
        for (size_t j = 0; j < n; ++j)
            u[j] = c[j][i];

        s += count(u);
    }

    answer(s);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> c(n, std::vector<unsigned>(m));
    std::cin >> c;

    solve(c);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
