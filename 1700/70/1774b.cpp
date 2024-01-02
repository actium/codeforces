#include <algorithm>
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

void solve(unsigned n, std::vector<unsigned>& a, unsigned k)
{
    const size_t m = a.size();

    std::sort(a.begin(), a.end());

    if (k > m)
        return answer(a.back() == 1);

    unsigned s = 0;
    for (size_t i = 0; i < m - k; ++i)
        s += a[i];

    unsigned t = 0;
    for (size_t i = m - k; a[i] < a.back(); ++i)
        t += a.back() - 1 - a[i];

    answer(s >= t);
}

void test_case()
{
    unsigned n, m, k;
    std::cin >> n >> m >> k;

    std::vector<unsigned> a(m);
    std::cin >> a;

    solve(n, a, k);
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