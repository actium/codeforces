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

void solve(const std::vector<unsigned>& x)
{
    const size_t n = x.size();

    unsigned f[32] = {};
    for (const unsigned q : x) {
        for (size_t i = 0; i < 32; ++i)
            f[i] += !!(q & 1 << i);
    }

    unsigned y = 0;
    for (size_t i = 0; i < 32; ++i) {
        if (2 * f[i] > n)
            y |= 1 << i;
    }

    answer(y);
}

void test_case()
{
    size_t n, l;
    std::cin >> n >> l;

    std::vector<unsigned> x(n);
    std::cin >> x;

    solve(x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
