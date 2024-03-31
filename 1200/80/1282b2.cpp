#include <algorithm>
#include <iostream>
#include <vector>

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

void solve(std::vector<unsigned>& a, unsigned p, unsigned k)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    std::vector<unsigned> s(k);
    for (size_t i = 0; i < k; ++i)
        s[i] = (i >= 1 ? s[i-1] : 0) + a[i];

    std::vector<unsigned> t(n);
    for (size_t i = k-1; i < n; ++i)
        t[i] = (i >= k ? t[i-k] : 0) + a[i];

    unsigned q = std::upper_bound(s.begin(), s.end(), p) - s.begin();
    for (size_t i = k-1; i < n; ++i) {
        if (t[i] > p)
            continue;

        const size_t d = (i + 1 - k) % k;

        const unsigned e = std::upper_bound(s.begin(), s.begin() + d, p - t[i]) - s.begin();
        q = std::max<unsigned>(q, i + 1 - d + e);
    }

    answer(q);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned p, k;
    std::cin >> p >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, p, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
