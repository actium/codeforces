#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Phase {
    unsigned t;
    union {
        unsigned x;
        struct {
            unsigned l;
            unsigned c;
        };
    };
};

std::istream& operator >>(std::istream& input, Phase& p)
{
    input >> p.t;
    return p.t == 1 ? input >> p.x : input >> p.l >> p.c;
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

struct Block {
    integer p;
    unsigned t;
    union {
        unsigned x;
        unsigned l;
    };
};

unsigned search(const std::vector<Block>& b, integer x)
{
    const auto it = std::upper_bound(b.begin(), b.end(), x, [](integer v, const Block& e) {
        return v < e.p;
    }) - 1;

    return it->t == 2 ? search(b, (x - it->p) % it->l) : it->x;
}

void solve(const std::vector<Phase>& p, const std::vector<integer>& q)
{
    const size_t m = q.size();

    std::vector<Block> b(1, { 0 });
    for (const Phase& e : p) {
        if (e.t == 1) {
            b.back().t = 1;
            b.back().x = e.x;
            b.push_back({ b.back().p + 1 });
        } else {
            b.back().t = 2;
            b.back().l = e.l;
            b.push_back({ b.back().p + 1ull * e.l * e.c });
        }
    }

    std::vector<unsigned> v(m);
    for (size_t i = 0; i < m; ++i)
        v[i] = search(b, q[i] - 1);

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t m;
    std::cin >> m;

    std::vector<Phase> p(m);
    std::cin >> p;

    size_t n;
    std::cin >> n;

    std::vector<integer> q(n);
    std::cin >> q;

    solve(p, q);

    return 0;
}
