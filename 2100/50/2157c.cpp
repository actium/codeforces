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
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

struct Query {
    unsigned c;
    unsigned l;
    unsigned r;
};

std::istream& operator >>(std::istream& input, Query& q)
{
    return input >> q.c >> q.l >> q.r;
}

void solve(unsigned n, unsigned k, const std::vector<Query>& r)
{
    std::vector<bool> min(n), mex(n);
    for (const Query& q : r) {
        for (unsigned i = q.l; i <= q.r; ++i)
            (q.c == 1 ? min : mex)[i-1] = true;
    }

    std::vector<unsigned> a(n);
    for (size_t i = 0, x = 0; i < n; ++i) {
        if (min[i] && mex[i])
            a[i] = k + 1;
        else
            a[i] = (min[i] ? k : x++ % k);
    }

    answer(a);
}

void test_case()
{
    unsigned n, k;
    std::cin >> n >> k;

    size_t q;
    std::cin >> q;

    std::vector<Query> r(q);
    std::cin >> r;

    solve(n, k, r);
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
