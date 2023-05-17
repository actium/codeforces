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

void answer(const std::vector<std::pair<size_t, size_t>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::pair<size_t, size_t>& x : v)
        std::cout << 1 + x.first << ' ' << 1 + x.second << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::set<std::pair<unsigned, size_t>> s;
    for (size_t i = 0; i < n; ++i)
        s.emplace(a[i], i);

    if (s.begin()->first == 1 && s.rbegin()->first != 1)
        return no_answer();

    std::vector<std::pair<size_t, size_t>> v;
    while (s.begin()->first != s.rbegin()->first) {
        const std::pair<unsigned, size_t> p = *s.rbegin();
        s.erase(std::prev(s.end()));

        const std::pair<unsigned, size_t>& q = *s.begin();
        v.emplace_back(p.second, q.second);

        s.emplace((p.first + q.first - 1) / q.first, p.second);
    }

    answer(v);
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
