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

void solve(const std::vector<unsigned>& a, unsigned k)
{
    const size_t n = a.size();

    unsigned f[31] = {};
    for (const unsigned x : a) {
        for (size_t i = 0; i < 31; ++i) {
            f[i] += (x >> i) & 0x1;
        }
    }

    unsigned x = 0;
    for (size_t i = 0; i < 31; ++i) {
        const unsigned d = n - f[30-i];
        if (d <= k) {
            x |= 1 << (30 - i);
            k -= d;
        }
    }

    answer(x);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
