#include <iostream>
#include <set>
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

void solve(const std::vector<int>& a, size_t k)
{
    const size_t n = a.size();

    std::set<int> s(a.cbegin(), a.cend());

    unsigned c = 1;
    for (size_t i = 1; i < n; ++i) {
        if (a[i] > a[i-1]) {
            const auto lb = s.lower_bound(a[i-1]), ub = s.lower_bound(a[i]);
            if (std::next(lb) == ub)
                continue;
        }
        ++c;
    }

    answer(c <= k);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
