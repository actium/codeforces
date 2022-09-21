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

unsigned lsb(unsigned x)
{
    return x & -x;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<integer> t(1 + n);

    const auto increase = [&](size_t x) {
        for (size_t i = 1 + x; i <= n; i += lsb(i))
            ++t[i];
    };

    const auto sum = [&](size_t k) {
        integer s = 0;
        for (size_t i = k; i > 0; i &= ~lsb(i))
            s += t[i];

        return s;
    };

    integer k = 0;
    for (size_t i = 0; i < n; ++i) {
        k += sum(n) - sum(a[i] - 1);
        increase(a[i] - 1);
    }

    answer(k);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
