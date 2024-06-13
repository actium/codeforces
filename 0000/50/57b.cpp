#include <iostream>
#include <vector>

using integer = long long;

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

struct Stair {
    unsigned a;
    unsigned b;
    unsigned c;
};

std::istream& operator >>(std::istream& input, Stair& s)
{
    return input >> s.a >> s.b >> s.c;
}

void solve(size_t n, const std::vector<Stair>& s, const std::vector<unsigned>& r)
{
    std::vector<integer> b(n + 2), d(n + 2);
    for (const Stair& e : s) {
        b[e.a] += e.c;
        b[e.b+1] -= e.b - e.a + e.c;
        d[e.a+1] += 1;
        d[e.b+1] -= 1;
    }

    for (size_t i = 1; i <= n; ++i) {
        d[i] += d[i-1];
        b[i] += b[i-1] + d[i];
    }

    integer q = 0;
    for (const unsigned x : r)
        q += b[x];

    answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<Stair> s(m);
    std::cin >> s;

    std::vector<unsigned> r(k);
    std::cin >> r;

    solve(n, s, r);

    return 0;
}
