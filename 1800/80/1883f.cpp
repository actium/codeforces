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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::map<unsigned, std::pair<size_t, size_t>> p;
    for (size_t i = 0; i < n; ++i) {
        const auto s = p.emplace(a[i], std::make_pair(i, i));
        if (!s.second)
            s.first->second.second = i;
    }

    std::vector<size_t> x;
    for (size_t i = 0; i < n; ++i) {
        if (p[a[i]].second == i)
            x.push_back(i);
    }

    integer k = 0;
    for (size_t i = 0; i < n; ++i) {
        if (p[a[i]].first == i)
            k += x.end() - std::lower_bound(x.begin(), x.end(), i);
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
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
