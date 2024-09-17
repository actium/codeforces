#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(std::vector<std::vector<unsigned>>& a, unsigned m)
{
    unsigned b = 0;
    for (std::vector<unsigned>& v : a) {
        std::sort(v.begin(), v.end());
        v.resize(std::unique(v.begin(), v.end()) - v.begin());

        unsigned x = 0, k = 0;
        for (const unsigned e : v) {
            if (e != x && (k++ == 1 || ++x != e))
                break;

            ++x;
        }

        b = std::max(b, x + (k == 0));
    }

    if (m <= b)
        return answer(b * (m + 1ull));

    answer(b * (b + 1ull) + (m + b + 1ull) * (m - b) / 2);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    std::vector<std::vector<unsigned>> a(n);
    for (size_t i = 0; i < n; ++i) {
        size_t l;
        std::cin >> l;

        a[i].resize(l);
        for (size_t j = 0; j < l; ++j)
            std::cin >> a[i][j];
    }

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
