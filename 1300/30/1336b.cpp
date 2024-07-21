#include <algorithm>
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

void answer(integer x)
{
    std::cout << x << '\n';
}

integer evaluate(integer x, integer y, integer z)
{
    if (x == oo || y == oo || z == oo)
        return oo;

    const integer p = std::max(x, y) - std::min(x, y);
    const integer q = std::max(y, z) - std::min(y, z);
    const integer r = std::max(z, x) - std::min(z, x);

    return p * p + q * q + r * r;
}

void solve(std::vector<unsigned>& r, std::vector<unsigned>& g, std::vector<unsigned>& b)
{
    std::sort(r.begin(), r.end());
    std::sort(g.begin(), g.end());
    std::sort(b.begin(), b.end());

    integer v = oo;

    const auto check = [&v](const std::vector<unsigned>& p, const std::vector<unsigned>& q, const std::vector<unsigned>& r) {
        for (const unsigned x : p) {
            const auto it = std::lower_bound(q.begin(), q.end(), x);
            const auto jt = std::lower_bound(r.begin(), r.end(), x);

            if (it != q.begin() && jt != r.begin())
                v = std::min(v, evaluate(*std::prev(it), *std::prev(jt), x));

            if (it != q.begin() && jt != r.end())
                v = std::min(v, evaluate(*std::prev(it), *jt, x));

            if (jt != r.begin() && it != q.end())
                v = std::min(v, evaluate(*it, *std::prev(jt), x));

            if (it != q.end() && jt != r.end())
                v = std::min(v, evaluate(x, *it, *jt));
        }
    };

    check(r, g, b);
    check(g, b, r);
    check(b, r, g);

    answer(v);
}

void test_case()
{
    size_t nr, ng, nb;
    std::cin >> nr >> ng >> nb;

    std::vector<unsigned> r(nr), g(ng), b(nb);
    std::cin >> r >> g >> b;

    solve(r, g, b);
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
