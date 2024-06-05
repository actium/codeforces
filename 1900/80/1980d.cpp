#include <iostream>
#include <numeric>
#include <vector>

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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> b(n);
    for (size_t i = 1; i < n; ++i)
        b[i] = std::gcd(a[i-1], a[i]);

    std::vector<bool> p(n, true);
    for (size_t i = 1; i < n; ++i)
        p[i] = p[i-1] && b[i] >= b[i-1];

    if (p[n-2])
        return answer(true);

    std::vector<bool> s(n, true);
    for (size_t i = n-2; i > 0; --i)
        s[i-1] = s[i] && b[i+1] >= b[i];

    if (s[1])
        return answer(true);

    for (size_t i = 1; i < n-1 && p[i-1]; ++i) {
        if (!s[i+1])
            continue;

        const unsigned c = std::gcd(a[i-1], a[i+1]);
        if (c >= b[i-1] && (i+2 == n || c <= b[i+2]))
            return answer(true);
    }

    answer(false);
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
