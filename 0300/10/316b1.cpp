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

unsigned prepare(const std::vector<unsigned>& a, size_t u, std::vector<unsigned>& d)
{
    if (d[u] == ~0u) {
        d[u] = 1;

        if (a[u] != 0) {
            const size_t p = a[u] - 1;
            d[u] += prepare(a, p, d);
            d[p] = 0;
        }
    }
    return d[u];
}

bool search(const std::vector<unsigned>& a, size_t u, unsigned x)
{
    if (a[u] == x)
        return true;

    return a[u] == 0 ? false : search(a, a[u] - 1, x);
}

void solve(const std::vector<unsigned>& a, unsigned x)
{
    const size_t n = a.size();

    std::vector<unsigned> p;
    {
        std::vector<unsigned> d(n, ~0u);
        p.push_back(prepare(a, x - 1, d));

        for (size_t i = 0; i < n; ++i)
            prepare(a, i, d);

        for (size_t i = 0; i < n; ++i) {
            if (d[i] != 0 && search(a, i, x))
                d[i] = 0;
        }
        d[x-1] = 0;

        std::vector<bool> t(1 + n);
        t[0] = true;
        for (const unsigned x : d) {
            if (x == 0)
                continue;

            for (size_t i = n; i >= x; --i)
                t[i] = t[i] || t[i-x];
        }

        for (unsigned k = 1; k + p[0] <= n; ++k) {
            if (t[k])
                p.push_back(k + p[0]);
        }
    }
    answer(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned x;
    std::cin >> x;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, x);

    return 0;
}
