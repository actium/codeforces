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

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    std::vector<integer> p(n);
    p[0] = a[0];
    for (size_t i = 1; i < n; ++i)
        p[i] = p[i-1] + std::abs(a[i]);

    std::vector<integer> s(n+1);
    for (size_t i = n-1; ~i != 0; --i)
        s[i] = s[i+1] - a[i];

    integer v = s[1];
    for (size_t i = 1; i < n; ++i)
        v = std::max(v, p[i-1] + s[i+1]);

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
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
