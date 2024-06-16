#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

struct Query {
    unsigned r[2];
    unsigned c[2];
};

std::istream& operator >>(std::istream& input, Query& q)
{
    return input >> q.r[0] >> q.c[0] >> q.r[1] >> q.c[1];
}

void solve(const std::vector<unsigned>& l, const std::vector<unsigned>& e, size_t v, const std::vector<Query>& r)
{
    const auto distance = [](unsigned s, unsigned t) {
        return std::max(s, t) - std::min(s, t);
    };

    const auto distance_l = [&](const Query& q, unsigned x) -> unsigned {
        return distance(q.c[0], x) + distance(q.r[0], q.r[1]) + distance(x, q.c[1]);
    };

    const auto distance_e = [&](const Query& q, unsigned x) -> unsigned {
        return distance(q.c[0], x) + (distance(q.r[0], q.r[1]) + v - 1) / v + distance(x, q.c[1]);
    };

    for (const Query& q : r) {
        unsigned d = ~0u;

        if (q.r[0] != q.r[1]) {
            const auto it = std::lower_bound(l.begin(), l.end(), q.c[0]);

            if (it != l.end())
                d = std::min(d, distance_l(q, *it));

            if (it != l.begin())
                d = std::min(d, distance_l(q, *std::prev(it)));

            const auto jt = std::lower_bound(e.begin(), e.end(), q.c[1]);

            if (jt != e.end())
                d = std::min(d, distance_e(q, *jt));

            if (jt != e.begin())
                d = std::min(d, distance_e(q, *std::prev(jt)));
        } else {
            d = distance(q.c[0], q.c[1]);
        }

        answer(d);
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m, cl, ce, v;
    std::cin >> n >> m >> cl >> ce >> v;

    std::vector<unsigned> l(cl), e(ce);
    std::cin >> l >> e;

    size_t q;
    std::cin >> q;

    std::vector<Query> r(q);
    std::cin >> r;

    solve(l, e, v, r);

    return 0;
}
