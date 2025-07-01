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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, integer k)
{
    unsigned c = 0;
    for (unsigned i = 0; i <= 60; ++i) {
        const integer mask = 1ull << i;

        for (integer x : a) {
            if ((x & mask) == 0 && k >= mask) {
                x |= mask;
                k -= mask;
            }

            c += x >> i & 1;
        }
    }

    answer(c);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    integer k;
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
