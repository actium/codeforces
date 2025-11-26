#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::pair<size_t, size_t>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::pair<size_t, size_t>& x : v)
        std::cout << 1+x.first << ' ' << 1+x.second << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& p, const std::string& x)
{
    const size_t n = p.size();

    const auto r = std::minmax_element(p.begin(), p.end());

    std::vector<std::pair<size_t, size_t>> v;
    v.emplace_back(0, r.first - p.begin());
    v.emplace_back(0, r.second - p.begin());
    v.emplace_back(r.first - p.begin(), n-1);
    v.emplace_back(r.second - p.begin(), n-1);
    v.push_back(std::minmax(r.first - p.begin(), r.second - p.begin()));

    std::string s(n, '0');
    for (const auto& [b, e] : v) {
        for (size_t i = b; i <= e; ++i) {
            const auto [lb, ub] = std::minmax(p[b], p[e]);
            if (lb < p[i] && p[i] < ub)
                ++s[i];
        }
    }

    for (size_t i = 0; i < n; ++i) {
        if (x[i] > s[i])
            return no_answer();
    }

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;

    std::string x;
    std::cin >> x;

    solve(p, x);
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
