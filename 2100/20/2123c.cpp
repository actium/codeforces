#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = (i == 0 ? a[0] : std::min(p[i-1], a[i]));

    std::vector<unsigned> s(n);
    for (size_t i = n-1; ~i != 0; --i)
        s[i] = (i == n-1 ? a[n-1] : std::max(s[i+1], a[i]));

    std::string v(n, '0');
    for (size_t i = 0; i < n; ++i)
        v[i] += (p[i] == a[i] || s[i] == a[i]);

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
