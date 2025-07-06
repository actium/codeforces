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

void solve(const std::vector<unsigned>& a, unsigned j, unsigned k)
{
    unsigned x = 0;
    for (const unsigned e : a)
        x = std::max(x, e);

    answer(k > 1 || a[j-1] == x);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned j, k;
    std::cin >> j >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, j, k);
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
