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

void solve(const std::vector<unsigned>& a, unsigned k)
{
    constexpr unsigned c[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };

    const auto test = [&](integer x) {
        integer q = 0;
        for (auto it = a.crbegin(); it != a.crend(); ++it) {
            q += x / c[*it];
            x %= c[*it];
        }
        return q <= k;
    };

    integer ub = 10;
    while (test(ub - 1))
        ub *= 10;

    for (integer d = ub / 10; d != 0; d /= 10) {
        while (!test(ub - d - (d > 1)))
            ub -= d;
    }

    answer(ub);
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
