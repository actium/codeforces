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

void answer(const std::vector<integer>& v)
{
    const char* separator = "";
    for (const integer x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> p(1+n);
    for (size_t i = 0; i < n; ++i)
        p[i+1] = std::max(p[i], a[i]);

    std::vector<integer> s(1+n);
    for (size_t i = n; i > 0; --i)
        s[i-1] = s[i] + a[i-1];

    std::vector<integer> v(n);
    for (size_t i = 0; i < n; ++i)
        v[i] = s[n-i] + p[n-i];

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
