#include <iostream>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size() - 1;

    std::vector<unsigned> ps[2] = { {0}, {0} };
    for (size_t i = 1; i < n; i += 2) {
        ps[0].push_back(a[i] - a[i-1]);
        ps[1].push_back(a[i+1] - a[i]);
    }
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 1; j < ps[i].size(); ++j)
            ps[i][j] += ps[i][j-1];
    }

    unsigned v = ps[0].back();
    for (size_t i = 1; i < n; ++i) {
        if (a[i] - a[i-1] > 1)
            v = std::max(v, ps[0][(i+1)/2] + ps[1].back() - ps[1][(i-1)/2] - 1);
    }

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    std::vector<unsigned> a(1 + n);
    for (size_t i = 1; i <= n; ++i)
        std::cin >> a[i];

    a.resize(n + 3, m);
    solve(a);

    return 0;
}
