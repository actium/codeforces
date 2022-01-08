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

void solve(const std::vector<std::vector<unsigned>>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> lb(n);
    for (size_t i = 0; i < n; ++i) {
        const size_t k = a[i].size();

        for (size_t j = 0; j < k; ++j) {
            if (a[i][j] >= j)
                lb[i] = std::max<unsigned>(lb[i], a[i][j] - j + 1);
        }
    }

    std::vector<size_t> o(n);
    for (size_t i = 0; i < n; ++i)
        o[i] = i;

    std::sort(o.begin(), o.end(), [&lb](size_t x, size_t y) { return lb[x] < lb[y]; });

    unsigned p = 0, b = 0;
    for (size_t i = 0; i < n; ++i) {
        if (p < lb[o[i]]) {
            b += lb[o[i]] - p;
            p = lb[o[i]];
        }
        p += a[o[i]].size();
    }

    answer(b);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<unsigned>> a(n);
    for (size_t i = 0; i < n; ++i) {
        size_t k;
        std::cin >> k;

        a[i].resize(k);
        std::cin >> a[i];
    }

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
