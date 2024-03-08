#include <iostream>
#include <map>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Query {
    unsigned t;
    integer u;
    integer v;
    unsigned w;
};

std::istream& operator >>(std::istream& input, Query& q)
{
    input >> q.t;
    return q.t == 1 ? input >> q.u >> q.v >> q.w : input >> q.u >> q.v;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<Query>& r)
{
    std::map<std::pair<integer, integer>, integer> c;
    for (const Query& q : r) {
        integer u = q.u, v = q.v, w = 0;
        while (u != v) {
            if (__builtin_clzll(u) > __builtin_clzll(v))
                std::swap(u, v);

            const integer p = u / 2;
            if (q.t == 1) {
                c[std::make_pair(p, u)] += q.w;
            } else {
                w += c[std::make_pair(p, u)];
            }

            u = p;
        }

        if (q.t == 2)
            answer(w);
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t q;
    std::cin >> q;

    std::vector<Query> r(q);
    std::cin >> r;

    solve(r);

    return 0;
}
