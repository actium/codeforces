#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::pair<unsigned, unsigned>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(std::vector<std::vector<unsigned>>& a, unsigned k)
{
    const size_t n = a.size(), m = a[0].size();

    std::vector<std::pair<unsigned, unsigned>> p;
    for (unsigned i = 1; i < m; ++i) {
        for (unsigned j = i + 1; j <= m; ++j)
            p.emplace_back(k == 0 ? i : j, k == 0 ? j : i);
    }

    answer(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    unsigned k;
    std::cin >> k;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(m));
    std::cin >> a;

    solve(a, k);

    return 0;
}
