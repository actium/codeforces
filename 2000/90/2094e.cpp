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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    integer f[30] = {};
    for (size_t i = 0; i < n; ++i) {
        for (unsigned x = a[i]; x != 0; x &= x-1)
            ++f[__builtin_ctz(x)];
    }

    const auto evaluate = [&](unsigned x) {
        integer s = 0;
        for (unsigned j = 0; j < 30; ++j) {
            const unsigned m = 1 << j;
            s += m * ((x & m) == 0 ? f[j] : n - f[j]);
        }
        return s;
    };

    integer v = 0;
    for (size_t i = 0; i < n; ++i)
        v = std::max(v, evaluate(a[i]));

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
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

/*
a xor b = a + b - 2 * (a and b)
a_k xor a_1 + a_k xor a_2 + ... = a_k + a_1 - 2 * (a_k and a_1) + a_k + a_2 - 2 * (a_k and a_2) + ... =
    = n * a_k + a_1 + a_2 + ... - 2 * (a_k and a_1 + a_k and a_2 + ...)


1000    2*2^3 + 4*2^2 + 1*2^1 + 3*2^0 = 16+16+2+3=37
1101    2*2^3 + 1*2^2 + 1*2^1 + 2*2^0 = 16+4+2+2=24
0100    3*2^3 + 1*2^2 + 1*2^1 + 3*2^0 = 24+4+2+3=33
0101
1111

2142
3413

*/