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

void solve(std::vector<integer>& a, integer k)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    std::vector<integer> d(n + 1);
    for (size_t i = 1; i < n && k > 0; ++i) {
        const integer q = a[i] - a[i-1];
        if (q * i <= k) {
            d[0] += q;
            d[i] -= q;
            k -= q * i;
        } else {
            d[0] += k / i + 1;
            d[k % i] -= 1;
            d[i] -= k / i;
            k = 0;
        }
    }
    d[0] += k / n + 1;
    d[k % n] -= 1;

    for (size_t i = 0; i < n; ++i) {
        a[i] += d[i];
        d[i+1] += d[i];
    }

    const integer x = *std::min_element(a.begin(), a.end());

    unsigned q = 0;
    for (const integer v : a)
        q += (v > x);

    answer(x * n - (n - 1) + q);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    integer k;
    std::cin >> k;

    std::vector<integer> a(n);
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
