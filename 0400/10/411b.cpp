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
    for (const unsigned x : v)
        std::cout << x << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& p, size_t k)
{
    const size_t n = p.size(), m = p[0].size();

    std::vector<unsigned> t(n), h(k);
    for (size_t j = 0; j < m; ++j) {
        std::vector<unsigned> b(k, ~0u);
        for (size_t i = 0; i < n; ++i) {
            const unsigned x = p[i][j];
            if (x == 0 || t[i] != 0)
                continue;

            if (b[x-1] == ~0u) {
                b[x-1] = i;
            } else {
                t[b[x-1]] = 1 + j;
                h[x-1] = 1 + j;
            }

            if (h[x-1] != 0)
                t[i] = 1 + j;
        }
    }

    answer(t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<unsigned>> p(n, std::vector<unsigned>(m));
    std::cin >> p;

    solve(p, k);

    return 0;
}
