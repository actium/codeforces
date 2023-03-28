#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Query {
    unsigned l;
    unsigned r;
    unsigned k;
};

std::istream& operator >>(std::istream& input, Query& v)
{
    return input >> v.l >> v.r >> v.k;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<Query>& r)
{
    using integer = unsigned long long;

    const size_t n = a.size();

    std::vector<integer> p(1 + n);
    for (size_t i = 0; i < n; ++i)
        p[1 + i] = p[i] + a[i];

    for (const Query& q : r) {
        const integer d = q.k * (q.r - q.l + 1ull);
        const integer s = p[n] - (p[q.r] - p[q.l-1]) + d;
        answer(s % 2 == 1);
    }
}

void test_case()
{
    size_t n, q;
    std::cin >> n >> q;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<Query> r(q);
    std::cin >> r;

    solve(a, r);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
