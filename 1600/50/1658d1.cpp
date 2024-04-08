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

void solve(unsigned lb, unsigned ub, const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned g[18] = {};
    for (unsigned i = lb; i <= ub; ++i) {
        for (unsigned x = i; x != 0; x &= x - 1)
            ++g[__builtin_ctz(x)];
    }

    unsigned f[18] = {};
    for (unsigned x : a) {
        while (x != 0) {
            ++f[__builtin_ctz(x)];
            x &= x - 1;
        }
    }

    unsigned x = 0;
    for (unsigned i = 0; i < 18; ++i) {
        if (f[i] != g[i])
            x |= 1 << i;
    }

    answer(x);
}

void test_case()
{
    unsigned lb, ub;
    std::cin >> lb >> ub;

    std::vector<unsigned> a(ub - lb + 1);
    std::cin >> a;

    solve(lb, ub, a);
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
