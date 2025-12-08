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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<int> b(n);
    for (size_t i = 0; i < n; ++i)
        b[i] = 2 * (i + 1) - a[i];

    integer d = 0, v = 0;
    for (size_t i = 0; i < n; ++i) {
        d = std::max<integer>(b[i], d + b[i]);
        v = std::max(v, d);
    }

    for (const unsigned x : a)
        v += x;

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
