#include <algorithm>
#include <iostream>
#include <vector>

constexpr unsigned M = 998244353;

unsigned long long P[51];

void initialize()
{
    P[0] = 1;
    for (unsigned i = 1; i <= 50; ++i)
        P[i] = P[i-1] * i % M;
}

unsigned raise(unsigned x, unsigned p)
{
    unsigned long long v = 1;
    while (p != 0) {
        if (p % 2 == 1)
            v = v * x % M;

        x = 1ull * x * x % M;
        p /= 2;
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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size() - 1;

    std::sort(a.begin() + 1, a.end());

    size_t x = 1;
    for ( ; a[x] < a[n]; ++x) {
        const unsigned d = a[n] - a[x] - 1;
        if (a[0] < d)
            return answer(0);

        a[0] -= d;
    }

    const size_t k = n - x + 1, m = std::min(k + a[0], n);
    answer(P[m] * raise(P[m-k], M-2) % M * P[x-1] % M);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(1+n);
    std::cin >> a;

    solve(a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    initialize();

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
