#include <algorithm>
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

void solve(const std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    std::vector<unsigned> p(1+n);
    for (size_t i = 0; i < n; ++i)
        p[i+1] = (p[i] + a[i]) % k;

    std::map<unsigned, std::vector<size_t>> x;
    for (size_t i = 0; i <= n; ++i)
        x[p[i]].push_back(i);

    integer c = 0;
    for (size_t i = k + 1; i <= n; ++i) {
        if (const auto it = x.find(p[i]); it != x.end())
            c += std::lower_bound(it->second.begin(), it->second.end(), i - k) - it->second.begin();
    }

    answer(c);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
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
