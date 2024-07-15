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

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::vector<unsigned>& a, unsigned k)
{
    const size_t n = a.size();

    std::map<unsigned, std::vector<unsigned>> b;
    for (const unsigned x : a)
        b[x % k].push_back(x);

    const auto count = [&](std::vector<unsigned>& v) {
        const size_t m = v.size();

        std::sort(v.begin(), v.end());

        std::vector<integer> p(1);
        for (size_t i = 1; i < m; i += 2)
            p.push_back(p.back() + (v[i] - v[i-1]) / k);

        if (m % 2 == 0)
            return std::make_pair(0, p.back());

        std::vector<integer> s(1);
        for (size_t i = m; i > 1; i -= 2)
            s.push_back(s.back() + (v[i-1] - v[i-2]) / k);

        integer t = p.back();
        for (size_t i = 0; i < p.size(); ++i)
            t = std::min(t, p[i] + s[s.size() - 1 - i]);

        return std::make_pair(1, t);
    };

    integer x = 0, q = 0;
    for (auto& e : b) {
        const std::pair<unsigned, integer> d = count(e.second);
        x += d.first;
        q += d.second;
    }

    x == n % 2 ? answer(q) : no_answer();
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

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
