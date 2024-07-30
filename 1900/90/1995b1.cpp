#include <algorithm>
#include <iostream>
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

void solve(std::vector<unsigned>& a, integer m)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    integer k = 0, t = 0;
    for (size_t i = 0, j = 0; j < n; ++j) {
        t += a[j];
        while (i < j && a[j] - a[i] > 1 || t > m)
            t -= a[i++];

        k = std::max(k, t);
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    integer m;
    std::cin >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, m);
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
