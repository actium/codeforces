#include <iostream>
#include <vector>

constexpr unsigned M = 1'000'000'007;

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

void add(unsigned& v, unsigned d)
{
    v = (v + d) % M;
}

void solve(const std::vector<unsigned>& a, unsigned k)
{
    std::vector<unsigned> p(64);
    for (const unsigned x : a) {
        std::vector<unsigned> d(64);
        for (size_t i = 0; i < 64; ++i)
            add(d[i&x], p[i]);

        for (size_t i = 0; i < 64; ++i)
            add(p[i], d[i]);

        add(p[x], 1);
    }

    unsigned q = 0;
    for (size_t i = 0; i < 64; ++i) {
        if (__builtin_popcount(i) == k)
            add(q, p[i]);
    }

    answer(q);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);
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
