#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size(), m = b.size();

    std::map<unsigned, size_t> p;
    for (size_t i = 0; i < n; ++i)
        p[a[i]] = i;

    std::vector<int> x(m, -1);
    for (size_t i = 0; i < m; ++i) {
        const auto it = p.lower_bound(b[i]);
        if (it != p.end())
            x[i] = it->second;
    }

    std::vector<std::pair<int, int>> q;
    q.reserve(m);
    for (size_t i = 0; i < m; ++i)
        q.emplace_back(x[i], -b[i]);

    std::sort(q.begin(), q.end());

    std::vector<unsigned> c;
    c.reserve(n + m);
    for (size_t i = 0, j = 0; i < n; ) {
        if (j < m && q[j].first == -1) {
            c.push_back(-q[j++].second);
            continue;
        }
        c.push_back(a[i]);
        while (j < m && q[j].first == i)
            c.push_back(-q[j++].second);
        ++i;
    }

    answer(c);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n), b(m);
    std::cin >> a >> b;

    solve(a, b);
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
