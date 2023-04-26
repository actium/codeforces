#include <iostream>
#include <numeric>
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
    integer s = 0;
    for (const unsigned q : a)
        s += q;

    integer x = 0, p = 0;
    for (const unsigned q : a) {
        p += q;
        if (p < s)
            x = std::max(x, std::gcd(p, s - p));
    }

    answer(x);
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
