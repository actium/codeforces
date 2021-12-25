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

void no_answer()
{
    std::cout << 0 << '\n';
}

void solve(const std::vector<integer>& a)
{
    const size_t n = a.size();

    integer d[2] = { a[0], a[1] };
    for (size_t i = 2; i < n; ++i)
        d[i%2] = std::gcd(d[i%2], a[i]);

    integer r[2] = { d[0], d[1] };
    for (size_t i = 0; i < n; ++i) {
        const size_t j = i % 2 ^ 1;
        r[i%2] = std::min(r[i%2], a[i] % d[j]);
    }

    if (r[0] == 0 && r[1] == 0)
        return no_answer();

    answer(r[0] == 0 ? d[0] : d[1]);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<integer> a(n);
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
