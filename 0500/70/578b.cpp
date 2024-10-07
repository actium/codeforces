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

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned k, unsigned x)
{
    const size_t n = a.size();

    std::vector<unsigned> p(1+n);
    for (size_t i = 0; i < n; ++i)
        p[i+1] = p[i] | a[i];

    std::vector<unsigned> s(n+1);
    for (size_t i = n; i > 0; --i)
        s[i-1] = s[i] | a[i-1];

    integer f = x;
    while (--k != 0)
        f *= x;

    integer v = 0;
    for (size_t i = 0; i < n; ++i)
        v = std::max(v, p[i] | a[i] * f | s[i+1]);

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned k, x;
    std::cin >> k >> x;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k, x);

    return 0;
}
