#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Query {
    char s;
    unsigned x;
    unsigned y;
};

std::istream& operator >>(std::istream& input, Query& v)
{
    return input >> v.s >> v.x >> v.y;
}

void solve(const std::vector<std::vector<unsigned>>& a, const std::vector<Query>& q)
{
    const size_t n = a.size(), m = a[0].size();

    std::vector<size_t> r(n);
    for (size_t i = 0; i < n; ++i)
        r[i] = i;

    std::vector<size_t> c(m);
    for (size_t i = 0; i < m; ++i)
        c[i] = i;

    for (const auto& o : q) {
        if (o.s == 'r')
            std::swap(r[o.x-1], r[o.y-1]);

        if (o.s == 'c')
            std::swap(c[o.x-1], c[o.y-1]);

        if (o.s == 'g')
            std::cout << a[r[o.x-1]][c[o.y-1]] << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(m));
    std::cin >> a;

    std::vector<Query> q(k);
    std::cin >> q;

    solve(a, q);

    return 0;
}

