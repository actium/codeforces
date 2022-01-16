#include <algorithm>
#include <iostream>
#include <vector>

using integer = long long;

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

void solve(std::vector<unsigned>& d)
{
    const size_t n = d.size();

    std::sort(d.begin(), d.end());

    integer b = 0;
    for (const unsigned x : d)
        b += x;

    integer c = d.back() - b;
    for (size_t i = 1; i < n; ++i) {
        b -= 1ll * (d[i] - d[i-1]) * (n - i);
        c -= b;
    }

    answer(c);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> d(n);
    std::cin >> d;

    solve(d);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
