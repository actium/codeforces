#include <iostream>
#include <vector>

using integer = long long;

struct Operation {
    unsigned l;
    unsigned r;
    unsigned d;
};

std::istream& operator >>(std::istream& input, Operation& v)
{
    return input >> v.l >> v.r >> v.d;
}

struct Query {
    unsigned x;
    unsigned y;
};

std::istream& operator >>(std::istream& input, Query& v)
{
    return input >> v.x >> v.y;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<integer>& v)
{
    const char* separator = "";
    for (const integer x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<Operation>& p, const std::vector<Query>& q)
{
    const size_t n = a.size(), m = p.size();

    std::vector<integer> b(1 + m);
    for (const Query& r : q) {
        ++b[r.x-1];
        --b[r.y];
    }
    for (size_t i = 1; i <= m; ++i)
        b[i] += b[i-1];

    std::vector<integer> d(1 + n);
    for (size_t i = 0; i < m; ++i) {
        const Operation& o = p[i];
        d[o.l-1] += b[i] * o.d;
        d[o.r] -= b[i] * o.d;
    }
    for (size_t i = 1; i <= n; ++i)
        d[i] += d[i-1];

    std::vector<integer> r(n);
    for (size_t i = 0; i < n; ++i)
        r[i] = a[i] + d[i];

    answer(r);
}

int main()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<Operation> p(m);
    std::cin >> p;

    std::vector<Query> q(k);
    std::cin >> q;

    solve(a, p, q);

    return 0;
}
