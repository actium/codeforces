#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

struct Triple {
    unsigned a;
    unsigned b;
    unsigned c;
};

std::istream& operator >>(std::istream& input, Triple& t)
{
    return input >> t.a >> t.b >> t.c;
}

void solve(const std::vector<Triple>& r, const std::vector<Triple>& w)
{
    unsigned s = 0;
    for (const Triple& x : r) {
        const unsigned p = 2 * (x.a + x.b);

        unsigned t = ~0u;
        for (const Triple& y : w) {
            if (y.a >= x.c) {
                const unsigned q = y.a / x.c * y.b;
                t = std::min(t, (p + q - 1) / q * y.c);
            }
        }

        s += t;
    }

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<Triple> r(n);
    std::cin >> r;

    size_t m;
    std::cin >> m;

    std::vector<Triple> w(m);
    std::cin >> w;

    solve(r, w);

    return 0;
}
