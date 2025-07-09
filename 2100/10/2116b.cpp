#include <iostream>
#include <vector>

constexpr unsigned M = 998244353;

unsigned raise(unsigned p)
{
    unsigned v = 1;
    for (auto b = 2ull; p != 0; p /= 2) {
        if (p % 2 == 1)
            v = v * b % M;

        b = b * b % M;
    }
    return v;
}

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

void solve(const std::vector<unsigned>& p, const std::vector<unsigned>& q)
{
    const size_t n = p.size();

    std::vector<unsigned> r(n);
    for (size_t i = 0, u = 0, v = 0; i < n; ++i) {
        if (p[i] > p[u])
            u = i;
        if (q[i] > q[v])
            v = i;

        if (p[u] > q[v] || p[u] == q[v] && q[i-u] > p[i-v])
            r[i] = (raise(p[u]) + raise(q[i-u])) % M;
        else
            r[i] = (raise(p[i-v]) + raise(q[v])) % M;
    }

    answer(r);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n), q(n);
    std::cin >> p >> q;

    solve(p, q);
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
