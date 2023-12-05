#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using integer = long long;

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

void solve(std::vector<int>& a)
{
    const size_t n = a.size();
    if (n == 1)
        return answer(1);

    std::sort(a.begin(), a.end());

    integer d = 0;
    for (const int x : a)
        d = std::gcd(d, x - a[0]);

    integer k = 0;
    for (const int x : a)
        k += (a[n-1] - x) / d;

    unsigned q = 1;
    while (q < n && std::binary_search(a.begin(), a.end(), a[n-1] - q * d))
        ++q;

    answer(k + q);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
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
