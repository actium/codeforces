#include <iostream>
#include <set>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::pair<integer, integer>& x)
{
    std::cout << x.first << ' ' << x.second << '\n';
}

void solve(const std::vector<unsigned>& v, const std::vector<unsigned>& p)
{
    const size_t n = v.size();

    std::pair<integer, integer> r = { 0, 0 };

    std::multiset<unsigned> s(v.begin(), v.end()), t;
    for (unsigned k = 1; 2 * k <= n + 1; ++k) {
        while (t.size() < k) {
            const auto it = std::prev(s.end());
            t.insert(*it);
            s.erase(it);
        }

        const integer c = integer(*t.begin()) * t.size();
        if (c > r.first)
            r = std::make_pair(c, t.size());

        const size_t i = p[k-1] - 1;
        if (const auto it = s.find(v[i]); it != s.end()) {
            s.erase(it);
        } else {
            t.erase(t.find(v[i]));
        }
    }

    answer(r);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> v(n), p(n);
    std::cin >> v >> p;

    solve(v, p);
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
