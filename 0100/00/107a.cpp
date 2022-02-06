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

struct Pipe {
    unsigned a;
    unsigned b;
    unsigned d;
};

std::istream& operator >>(std::istream& input, Pipe& v)
{
    return input >> v.a >> v.b >> v.d;
}

void answer(const std::vector<std::vector<unsigned>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::vector<unsigned>& x : v)
        std::cout << x[0] << ' ' << x[1] << ' ' << x[2] << '\n';
}

void solve(size_t n, const std::vector<Pipe>& p)
{
    const size_t m = p.size();

    std::vector<size_t> a(n, m), s(n, m);
    for (size_t i = 0; i < m; ++i) {
        a[p[i].b-1] = i;
        s[p[i].a-1] = i;
    }

    std::vector<std::vector<unsigned>> t;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] == m || s[i] != m)
            continue;

        size_t j = a[i];
        unsigned d = p[j].d;
        while (a[p[j].a-1] != m) {
            j = a[p[j].a-1];
            d = std::min(d, p[j].d);
        }

        t.push_back({ p[j].a, 1+i, d });
    }

    std::sort(t.begin(), t.end());

    answer(t);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<Pipe> p(m);
    std::cin >> p;

    solve(n, p);

    return 0;
}
