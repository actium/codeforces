#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

constexpr unsigned M = 998244353;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, std::vector<unsigned>& b)
{
    const size_t n = a.size();

    std::vector<integer> c(n);
    for (size_t i = 0; i < n; ++i)
        c[i] = (i + 1ull) * (n - i) * a[i];

    std::sort(b.begin(), b.end(), std::greater<unsigned>());
    std::sort(c.begin(), c.end());

    unsigned s = 0;
    for (size_t i = 0; i < n; ++i)
        s = (s + c[i] % M * b[i]) % M;

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}
