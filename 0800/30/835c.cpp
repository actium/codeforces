#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Star {
    unsigned x;
    unsigned y;
    unsigned s;
};

std::istream& operator >>(std::istream& input, Star& s)
{
    return input >> s.x >> s.y >> s.s;
}

struct Query {
    unsigned t;
    unsigned x1;
    unsigned y1;
    unsigned x2;
    unsigned y2;
};

std::istream& operator >>(std::istream& input, Query& q)
{
    return input >> q.t >> q.x1 >> q.y1 >> q.x2 >> q.y2;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<Star>& s, unsigned c, const std::vector<Query>& r)
{
    unsigned p[102][102][11] = {};

    const auto sum = [&](unsigned x, unsigned y, unsigned t) {
        unsigned s = 0;
        for (unsigned i = 1 + x; i > 0; i &= i - 1) {
            for (unsigned j = 1 + y; j > 0; j &= j - 1)
                s += p[i][j][t];
        }
        return s;
    };

    for (const Star& q : s) {
        for (unsigned i = 1 + q.x; i <= 101; i += 1 << __builtin_ctz(i)) {
            for (unsigned j = 1 + q.y; j <= 101; j += 1 << __builtin_ctz(j)) {
                for (unsigned t = 0; t <= c; ++t)
                    p[i][j][t] += (q.s + t) % (c + 1);
            }
        }
    }

    for (const Query& q : r) {
        const unsigned t = q.t % (c + 1);

        unsigned s = 0;
        s += sum(q.x2, q.y2, t);
        s -= sum(q.x1 - 1, q.y2, t);
        s -= sum(q.x2, q.y1 - 1, t);
        s += sum(q.x1 - 1, q.y1 - 1, t);

        answer(s);
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, q;
    std::cin >> n >> q;

    unsigned c;
    std::cin >> c;

    std::vector<Star> s(n);
    std::cin >> s;

    std::vector<Query> r(q);
    std::cin >> r;

    solve(s, c, r);

    return 0;
}
