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

void solve(const std::vector<unsigned>& a, size_t k, integer x)
{
    const size_t n = a.size();

    integer p = 0;
    for (const unsigned v : a)
        p += v;

    if (p * k < x)
        return answer(0);

    integer m = x / p, q = m * n, s = m * p;
    for (auto it = a.rbegin(); s < x; s += *it++)
        ++q;

    answer(1ull * k * n - q + 1);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    integer x;
    std::cin >> x;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k, x);
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
