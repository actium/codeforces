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

void solve(std::vector<integer>& a, size_t k)
{
    const size_t n = a.size();

    if (k > 2)
        return answer(0);

    std::sort(a.begin(), a.end());

    integer x = a[0];
    for (size_t i = 1; i < n; ++i)
        x = std::min(x, a[i] - a[i-1]);

    if (k == 2) {
        for (size_t i = 1; i < n; ++i) {
            for (size_t j = 0; j < i; ++j) {
                const integer d = a[i] - a[j];

                auto it = std::lower_bound(a.begin(), a.end(), d);
                if (it != a.end())
                    x = std::min(x, *it - d);

                if (it-- != a.begin())
                    x = std::min(x, d - *it);
            }
        }
    }

    answer(x);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

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
