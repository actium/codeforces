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
    char t;
    unsigned lb;
    unsigned ub;
};

std::istream& operator >>(std::istream& input, Query& q)
{
    return input >> q.t >> q.lb >> q.ub;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<Query>& r)
{
    const size_t m = r.size();

    unsigned max = 0;
    for (const unsigned x : a)
        max = std::max(max, x);

    std::vector<unsigned> v(m);
    for (size_t i = 0; i < m; ++i) {
        if (r[i].lb <= max && r[i].ub >= max)
            max += (r[i].t == '+' ? 1 : -1);

        v[i] = max;
    }

    answer(v);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<Query> r(m);
    std::cin >> r;

    solve(a, r);
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
