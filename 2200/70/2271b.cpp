#include <iostream>
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

void solve(const std::vector<unsigned>& a, unsigned k)
{
    const size_t n = a.size();

    std::vector<unsigned> f(1+n);
    for (const unsigned x : a)
        ++f[x];

    unsigned x = 0;
    while (x <= n && f[x] >= 2 * k)
        ++x;

    answer(x <= n && f[x] == 2 * k - 1);
}

void test_case()
{
    size_t n;
    std::cin >> n;
    
    unsigned k;
    std::cin >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);
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
