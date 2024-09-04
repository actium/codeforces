#include <iostream>
#include <vector>

using integer = unsigned long long;

constexpr integer oo = ~integer(0);

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Query {
    unsigned t;
    unsigned a;
    unsigned b;
    unsigned n;
};

std::istream& operator >>(std::istream& input, Query& q)
{
    input >> q.t >> q.a >> q.b;
    return q.t == 1 ? input >> q.n : input;
}

void answer(const std::vector<long long>& v)
{
    const char* separator = "";
    for (const long long x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<Query>& r)
{
    const size_t m = r.size();

    std::vector<long long> s(m);
    {
        integer lb = 1, ub = oo;
        for (size_t i = 0; i < m; ++i) {
            if (r[i].t == 1 && r[i].n == 1) {
                if (r[i].a >= lb) {
                    ub = std::min<integer>(ub, r[i].a);
                    s[i] = 1;
                }
                continue;
            }

            const integer d = r[i].a - r[i].b;
            if (r[i].t == 1) {
                const integer t = (r[i].n - 1) * d;
                if (t + r[i].a >= lb && t + r[i].b < ub) {
                    lb = std::max(lb, t + r[i].b + 1);
                    ub = std::min(ub, t + r[i].a);
                    s[i] = 1;
                }
            } else {
                integer u = (r[i].a >= lb ? 0 : (lb - r[i].a) / d);
                if (u * d + r[i].a < lb)
                    ++u;

                integer v = (r[i].a >= ub ? 0 : (ub - r[i].a) / d);
                if (v * d + r[i].a < ub)
                    ++v;

                s[i] = (u == v ? u + 1 : -1);
            }
        }
    }
    answer(s);
}

void test_case()
{
    size_t q;
    std::cin >> q;

    std::vector<Query> r(q);
    std::cin >> r;

    solve(r);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
