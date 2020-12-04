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

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> d(n);
    for (size_t i = 1; i < n; ++i)
        d[i] = abs(a[i] - a[i-1]);

    integer s = 0;
    for (size_t i = 1; i < n; ++i)
        s += d[i];

    integer k = std::min(s - d[1], s - d[n-1]);
    for (size_t i = 1; i < n-1; ++i)
        k = std::min(k, s - d[i] - d[i+1] + abs(a[i+1] - a[i-1]));

    answer(k);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

