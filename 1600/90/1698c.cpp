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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(std::vector<int>& a)
{
    size_t n = a.size();

    std::sort(a.begin(), a.end());

    if (a[2] < 0 || a[n-3] > 0)
        return answer(false);

    if (n > 6) {
        a[4] = a[n-2];
        a[5] = a[n-1];
        a.resize(n = 6);
    }

    for (size_t i = 2; i < n; ++i) {
        for (size_t j = 1; j < i; ++j) {
            for (size_t k = 0; k < j; ++k) {
                const long long x = 0LL + a[i] + a[j] + a[k];
                if (std::abs(x) > 1'000'000'000 || !std::binary_search(a.cbegin(), a.cend(), x))
                    return answer(false);
            }
        }
    }

    answer(true);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

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
