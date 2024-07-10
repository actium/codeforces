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

unsigned count(unsigned a, unsigned b, unsigned k)
{
    unsigned s = b, t = b + 1, z = 10;
    for (unsigned i = 1; i < k; ++i) {
        s *= 10;
        t *= 10;
        z *= 10;
    }

    const unsigned d = (s > 0 ? (s - 1) / a + 1 : 0);
    return (z - 1) / a - (t - 1) / a + d;
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, unsigned k)
{
    const size_t n = a.size();

    unsigned q = 1;
    for (size_t i = 0; i < n; ++i)
        q = 1ull * q * count(a[i], b[i], k) % M;

    answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n / k), b(n / k);
    std::cin >> a >> b;

    solve(a, b, k);

    return 0;
}
