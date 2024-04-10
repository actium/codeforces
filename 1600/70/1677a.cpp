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

void solve(const std::vector<unsigned>& p)
{
    const size_t n = p.size();

    std::vector<std::vector<size_t>> px(n);
    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (p[j] < p[i])
                px[i].push_back(j);
        }
    }

    std::vector<std::vector<size_t>> sx(n);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            if (p[j] < p[i])
                sx[i].push_back(j);
        }
    }

    integer k = 0;
    for (size_t c = 0; c < n; ++c) {
        for (size_t b = 0; b < c; ++b) {
            const auto ka = std::lower_bound(px[c].begin(), px[c].end(), b) - px[c].begin();
            const auto kd = sx[b].end() - std::upper_bound(sx[b].begin(), sx[b].end(), c);
            k += ka * kd;
        }
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(p);
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
