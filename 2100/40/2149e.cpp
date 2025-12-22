#include <iostream>
#include <map>
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

void solve(const std::vector<unsigned>& a, unsigned k, unsigned l, unsigned r)
{
    const size_t n = a.size();

    integer q = 0;
    {
        std::map<unsigned, unsigned> f, g;
        for (size_t x = 0, i = 0, j = 0; x < n; ++x) {
            while (i < n && (i - x < l || f.size() < k))
                ++f[a[i++]];

            while (j < n && (j - x <= r && g.size() <= k))
                ++g[a[j++]];

            if (l <= i - x && i - x <= r && f.size() == k)
                q += j - i + (j - x <= r && g.size() == k);

            if (--f[a[x]] == 0)
                f.erase(a[x]);

            if (--g[a[x]] == 0)
                g.erase(a[x]);
        }
    }

    answer(q);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k, l, r;
    std::cin >> k >> l >> r;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k, l, r);
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
