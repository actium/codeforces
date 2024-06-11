#include <iostream>
#include <vector>

constexpr unsigned oo = ~0u;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Query {
    char t;
    unsigned id;
    unsigned hash;
};

std::istream& operator >>(std::istream& input, Query& q)
{
    input >> q.t >> q.id;
    return q.t == '+' ? input >> q.hash : input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(size_t h, size_t m, const std::vector<Query>& r)
{
    std::vector<unsigned> t(h, oo);

    unsigned k = 0;
    for (const Query& q : r) {
        if (q.t == '+') {
            size_t x = q.hash;
            while (t[x % h] != oo) {
                x += m;
                ++k;
            }
            t[x % h] = q.id;
        } else {
            size_t x = 0;
            while (t[x] != q.id)
                ++x;

            t[x] = oo;
        }
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t h, m, n;
    std::cin >> h >> m >> n;

    std::vector<Query> r(n);
    std::cin >> r;

    solve(h, m, r);

    return 0;
}
