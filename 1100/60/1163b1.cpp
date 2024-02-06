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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& u)
{
    const size_t n = u.size();

    unsigned f[10] = {}, k = 0;
    for (size_t i = 0; i < n; ++i) {
        ++f[u[i]-1];

        std::vector<unsigned> c;
        for (size_t j = 0; j < 10; ++j) {
            if (f[j] != 0)
                c.push_back(j);
        }

        const size_t m = c.size();
        if (m == 1) {
            k = i + 1;
            continue;
        }

        for (size_t j = 0; j < m; ++j)
            c[j] = f[c[j]];

        std::sort(c.begin(), c.end());

        if (c[0] == 1 && c[1] == c[m-1] || c[0] == c[m-2] && c[m-2] + 1 == c[m-1])
            k = i + 1;
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> u(n);
    std::cin >> u;

    solve(u);

    return 0;
}
