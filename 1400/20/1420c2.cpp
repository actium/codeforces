#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

unsigned long long solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned long long p = a[0];
    for (size_t i = 1; i < n; ++i) {
        if (a[i] > a[i-1])
            p += a[i] - a[i-1];
    }

    return p;
}

long long update(std::vector<unsigned>& a, size_t i, unsigned v)
{
    const unsigned p = (i > 0 ? a[i-1] : 0);
    const unsigned q = (i+1 < a.size() ? a[i+1] : 0);

    long long delta = 0;

    if (a[i] > p)
        delta -= a[i] - p;

    if (q > a[i])
        delta -= q - a[i];

    if (v > p)
        delta += v - p;

    if (q > v)
        delta += q - v;

    a[i] = v;

    return delta;
}

long long change(std::vector<unsigned>& a, size_t l, size_t r)
{
    long long delta = 0;

    const unsigned x = a[l];
    delta += update(a, l, a[r]);
    delta += update(a, r, x);

    return delta;
}

void test_case()
{
    size_t n, q;
    std::cin >> n >> q;

    std::vector<unsigned> a(n);
    std::cin >> a;

    unsigned long long p = solve(a);
    answer(p);

    while (q-- > 0) {
        size_t l, r;
        std::cin >> l >> r;

        p += change(a, l-1, r-1);
        answer(p);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

