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

struct Planet {
    std::string x;

    std::vector<unsigned> a;
    std::vector<unsigned> b;
    std::vector<unsigned> c;
};

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<Planet>& p, unsigned k)
{
    const size_t n = p.size(), m = p[0].a.size();

    std::vector<size_t> x(m);
    for (size_t i = 0; i < m; ++i)
        x[i] = i;

    unsigned b = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            std::vector<unsigned> d(m);
            for (size_t q = 0; q < m; ++q) {
                if (p[i].a[q] < p[j].b[q])
                    d[q] = p[j].b[q] - p[i].a[q];
            }

            std::sort(x.begin(), x.end(), [&d](size_t a, size_t b) { return d[a] > d[b]; });

            unsigned r = k, s = 0;
            for (const size_t q : x) {
                const unsigned v = std::min(r, p[i].c[q]);
                s += d[q] * v, r -= v;
            }

            b = std::max(b, s);
        }
    }

    answer(b);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    unsigned k;
    std::cin >> k;

    std::vector<Planet> p(n);
    for (Planet& v : p) {
        std::cin >> v.x;

        v.a.resize(m);
        v.b.resize(m);
        v.c.resize(m);

        for (size_t i = 0; i < m; ++i)
            std::cin >> v.a[i] >> v.b[i] >> v.c[i];
    }

    solve(p, k);

    return 0;
}

