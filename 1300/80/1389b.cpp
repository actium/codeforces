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

void solve(const std::vector<unsigned>& a, size_t k, size_t z)
{
    const size_t n = a.size();

    std::vector<unsigned> p(1 + n);
    for (size_t i = 0; i < n; ++i)
        p[i+1] = p[i] + a[i];

    unsigned s = 0;
    for (size_t i = 1; i <= k; ++i) {
        const size_t q = std::min((k - i) / 2, z), r = k - i - 2 * q;

        unsigned t = p[i+1] + q * (a[i-1] + a[i]);
        if (z > q && r != 0)
            t += a[i-1];
        else
            t += p[i+r+1] - p[i+1];

        s = std::max(s, t);
    }

    answer(s);
}

void test_case()
{
    size_t n, k, z;
    std::cin >> n >> k >> z;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k, z);
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
