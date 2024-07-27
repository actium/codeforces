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

void solve(std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    integer v = 0;
    for (size_t i = 0; i < n; ++i) {
        v += a[i];
        a[i] += i + 1;
    }

    std::sort(a.begin(), a.end(), std::greater<unsigned>());

    for (size_t i = 0; i < k; ++i)
        v += int(n - i - a[i]);

    answer(v);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

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
