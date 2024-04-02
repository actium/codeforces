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
    unsigned t;
    unsigned p;
    unsigned x;
};

std::istream& operator >>(std::istream& input, Query& q)
{
    input >> q.t;
    return q.t == 1 ? input >> q.p >> q.x : input >> q.x;
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

void solve(std::vector<unsigned>& a, const std::vector<Query>& r)
{
    const size_t n = a.size(), m = r.size();

    std::vector<unsigned> x(m + 1);
    for (size_t i = m-1; ~i != 0; --i) {
        if (r[i].t == 2)
            x[i] = r[i].x;

        x[i] = std::max(x[i], x[i+1]);
    }

    for (size_t i = 0; i < n; ++i)
        a[i] = std::max(a[i], x[0]);

    for (size_t i = 0; i < m; ++i) {
        if (r[i].t == 1)
            a[r[i].p-1] = std::max(r[i].x, x[i]);
    }

    answer(a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    size_t q;
    std::cin >> q;

    std::vector<Query> r(q);
    std::cin >> r;

    solve(a, r);

    return 0;
}
