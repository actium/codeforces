#include <algorithm>
#include <iostream>
#include <vector>

using integer = long long;

constexpr integer M = 998244353;

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
    using pair_t = std::pair<integer, integer>;

    std::vector<pair_t> v = { pair_t(0, 1) };
    for (const int x : a) {
        std::vector<pair_t> s;
        for (const pair_t& p : v) {
            s.emplace_back(p.first + x, p.second);
            s.emplace_back(std::abs(p.first + x), p.second);
        }

        std::sort(s.begin(), s.end());

        std::swap(s[1], s.back());
        while (s.size() > 2) {
            if (s.back().first == s[0].first || s.back().first == s[1].first)
                s[s.back().first == s[1].first].second += s.back().second;

            s.pop_back();
        }
        if (s[1].first == s[0].first) {
            s[0].second += s[1].second;
            s.pop_back();
        }

        for (pair_t& p : s)
            p.second %= M;

        std::swap(v, s);
    }

    answer(v.back().second);
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
