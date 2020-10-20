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

void no_answer()
{
    std::cout << "NO" << '\n';
}

void answer(const std::vector<std::pair<size_t, size_t>>& v)
{
    std::cout << "YES" << '\n';

    for (const auto& x : v)
        std::cout << 1+x.first << ' ' << 1+x.second << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    const auto x = std::find_if(a.cbegin(), a.cend(), [&](unsigned x) { return x != a[0]; });
    if (x == a.cend())
        return no_answer();

    std::vector<std::pair<size_t, size_t>> p;
    for (size_t i = 1; i < n; ++i)
        p.emplace_back(i, a[i] != a[0] ? 0 : x - a.cbegin());

    answer(p);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

