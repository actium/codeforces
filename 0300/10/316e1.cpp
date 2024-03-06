#include <iostream>
#include <vector>

constexpr unsigned M = 1000000000;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Query {
    unsigned t;
    union {
        struct {
            unsigned x;
            unsigned v;
        };
        struct {
            unsigned l;
            unsigned r;
        };
    };
};

std::istream& operator >>(std::istream& input, Query& q)
{
    return input >> q.t >> q.x >> q.v;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a, const std::vector<Query>& r)
{
    std::vector<unsigned> f = { 1, 1 };
    for (size_t i = 2; i < 100; ++i)
        f.push_back((f[i-1] + f[i-2]) % M);

    for (const Query& q : r) {
        if (q.t == 1) {
            a[q.x-1] = q.v;
        } else {
            unsigned s = 0;
            for (unsigned i = q.l; i <= q.r; ++i)
                s = (s + 1ull * a[i-1] * f[i - q.l]) % M;

            answer(s);
        }
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<Query> r(m);
    std::cin >> r;

    solve(a, r);

    return 0;
}
