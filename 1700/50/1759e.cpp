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

void solve(std::vector<unsigned>& a, unsigned h)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    const auto count = [&](const std::vector<unsigned>& x) {
        unsigned k = 0;

        unsigned long long p = h;
        for (const unsigned f : x) {
            while (k < n && a[k] < p)
                p += a[k++] / 2;

            p *= f;
        }

        return k;
    };

    unsigned k = 0;
    k = std::max(k, count({2, 2, 3, 0}));
    k = std::max(k, count({2, 3, 2, 0}));
    k = std::max(k, count({3, 2, 2, 0}));
    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned h;
    std::cin >> h;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, h);
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
