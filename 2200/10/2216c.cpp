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

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, size_t k, unsigned p, unsigned q)
{
    const size_t n = a.size();

    std::vector<unsigned> b(n), c(n), d(n);
    for (size_t i = 0; i < n; ++i) {
        b[i] = a[i] % q % p;
        c[i] = a[i] % p;
        d[i] = std::min(b[i], c[i]);
    }

    integer v = 0;
    for (const unsigned x : c)
        v += x;

    integer t[2] = {};
    for (size_t i = 0; i < k; ++i) {
        t[0] += b[i];
        t[1] += c[i];
    }
    for (size_t i = k; i < n; ++i) {
        t[0] += d[i];
        t[1] += d[i];
    }

    v = std::min(v, std::min(t[0], t[1]));
    for (size_t i = k; i < n; ++i) {
        t[0] += 0ull + (d[i-k] + b[i]) - (b[i-k] + d[i]);
        t[1] += 0ull + (d[i-k] + c[i]) - (c[i-k] + d[i]);
        v = std::min(v, std::min(t[0], t[1]));
    }

    answer(v);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    unsigned p, q;
    std::cin >> p >> q;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k, p, q);
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
