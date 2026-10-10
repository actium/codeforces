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

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    std::map<int, std::vector<size_t>> s;
    for (size_t i = 4; i < n; ++i)
        s[a[i-4] + a[i-2] - a[i]].push_back(i);

    integer k = 0;
    for (const auto& [_, v] : s) {
        for (auto it = v.begin(); it != v.end(); ++it) {
            auto jt = std::lower_bound(v.begin(), it, *it - 4);
            for (k += jt - v.begin(); jt != it; ++jt) {
                if (*jt % 2 != *it % 2)
                    ++k;
            }
        }
    }

    answer(k);
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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
