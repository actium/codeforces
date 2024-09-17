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
    unsigned x;
};

std::istream& operator >>(std::istream& input, Query& q)
{
    return input >> q.l >> q.r >> q.x;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<Query>& r)
{
    const size_t n = a.size();

    std::vector<size_t> p(n);
    p[n-1] = n;
    for (size_t i = n-2; ~i != 0; --i)
        p[i] = (a[i] == a[i+1] ? p[i+1] : i+1);

    for (const Query& q : r) {
        if (a[q.l-1] != q.x) {
            answer(q.l);
            continue;
        }
        if (p[q.l-1] < q.r) {
            answer(p[q.l-1] + 1);
            continue;
        }
        no_answer();
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
