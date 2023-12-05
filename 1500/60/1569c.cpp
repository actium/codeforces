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

unsigned f(unsigned n)
{
    static std::vector<integer> t = { 1, 1 };

    while (t.size() <= n)
        t.push_back(t.back() * t.size() % M);

    return t[n];
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    const unsigned x = *std::max_element(a.begin(), a.end());
    if (std::count(a.begin(), a.end(), x) > 1)
        return answer(f(n));

    const unsigned c = std::count(a.begin(), a.end(), x - 1);

    integer k = f(c);
    for (unsigned i = c + 2; i <= n; ++i)
        k = k * i % M;

    answer((f(n) - k + M) % M);
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
