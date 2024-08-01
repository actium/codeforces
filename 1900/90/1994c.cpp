#include <algorithm>
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

void solve(const std::vector<unsigned>& a, unsigned x)
{
    const size_t n = a.size();

    std::vector<integer> ps(1+n);
    for (size_t i = 0; i < n; ++i)
        ps[i+1] = ps[i] + a[i];

    std::vector<unsigned> c(n+1);
    for (size_t i = n-1; ~i != 0; --i) {
        const auto it = std::upper_bound(ps.begin(), ps.end(), ps[i] + x);
        if (it != ps.end())
            c[i] += c[it-ps.begin()] + 1;
    }

    integer k = n * (n + 1ull) / 2;
    for (const unsigned x : c)
        k -= x;

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned x;
    std::cin >> x;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, x);
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
