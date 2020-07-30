#include <iostream>
#include <vector>

struct Query {
    unsigned ta, fa;
    unsigned tb, fb;
};

std::istream& operator >>(std::istream& input, Query& q)
{
    return input >> q.ta >> q.fa >> q.tb >> q.fb;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned h, unsigned a, unsigned b, const std::vector<Query>& q)
{
    for (const Query& x : q) {
        if (x.ta == x.tb) {
            answer(std::max(x.fa, x.fb) - std::min(x.fa, x.fb));
        } else {
            const unsigned f = std::max(a, std::min(x.fa, b));
            const unsigned t1 = std::max(f, x.fa) - std::min(f, x.fa);
            const unsigned t2 = std::max(f, x.fb) - std::min(f, x.fb);
            answer(t1 + std::max(x.ta, x.tb) - std::min(x.ta, x.tb) + t2);
        }
    }
}

int main()
{
    unsigned n, h, a, b;
    std::cin >> n >> h >> a >> b;

    size_t k;
    std::cin >> k;

    std::vector<Query> q(k);
    std::cin >> q;

    solve(n, h, a, b, q);

    return 0;
}

