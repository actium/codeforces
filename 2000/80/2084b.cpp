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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<integer>& a)
{
    const size_t n = a.size();

    size_t x = 0;
    for (size_t i = 1; i < n; ++i) {
        if (a[i] < a[x])
            x = i;
    }

    integer g = 0;
    for (size_t i = 0; i < n; ++i) {
        if (i != x && a[i] % a[x] == 0)
            g = std::gcd(g, a[i]);
    }

    answer(g == a[x]);
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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
