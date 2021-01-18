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

unsigned g(unsigned x)
{
    if (x < 10)
        return x;

    unsigned p = 1;
    for ( ; x != 0; x /= 10) {
        const unsigned d = x % 10;
        if (d != 0)
            p *= d;
    }
    return g(p);
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<Query>& q)
{
    constexpr size_t N = 1000000;

    std::vector<std::vector<unsigned>> t(10, std::vector<unsigned>(1+N));
    for (unsigned x = 1; x <= N; ++x)
        ++t[g(x)][x];

    for (size_t k = 1; k < 10; ++k) {
        for (size_t i = 1; i <= N; ++i)
            t[k][i] += t[k][i-1];
    }

    for (const auto [l, r, k] : q)
        answer(t[k][r] - t[k][l-1]);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<Query> q(n);
    std::cin >> q;

    solve(q);

    return 0;
}

