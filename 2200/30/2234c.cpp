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

integer solve(const std::vector<unsigned>& a, size_t x)
{
    const size_t n = a.size();

    std::vector<unsigned> p(n);
    for (size_t d = 1; d < n; ++d) {
        const size_t i = (n + x - d) % n, j = (i + 1) % n;
        p[i] = std::max(p[j], a[i]);
    }

    std::vector<unsigned> s(n);
    for (size_t d = 1; d < n; ++d) {
        const size_t i = (x + d - 1) % n, j = (i + 1) % n;
        s[j] = std::max(s[i], a[i]);
    }

    integer t = 0;
    for (size_t i = 0; i < n; ++i)
        t += std::min(p[i], s[i]);

    return t;
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<integer> v(n);
    for (size_t i = 0; i < n; ++i)
        v[i] = solve(a, i);

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
