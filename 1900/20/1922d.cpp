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

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a, std::vector<unsigned>& d)
{
    const size_t n = a.size();

    std::vector<std::pair<int, int>> p(n);

    std::vector<size_t> q;
    for (size_t i = 0; i < n; ++i) {
        p[i] = std::make_pair(i-1, i+1);
        q.push_back(i);
    }

    std::vector<unsigned> r(n);
    for (size_t i = 0; i < n; ++i) {
        std::vector<size_t> t;
        for (const size_t x : q) {
            if ((p[x].first != -1 ? a[p[x].first] : 0) + (p[x].second != n ? a[p[x].second] : 0) > d[x]) {
                d[x] = 0;
                t.push_back(x);
            }
        }
        r[i] = t.size();

        q.clear();

        for (const size_t x : t) {
            if (p[x].second == n)
                continue;

            p[p[x].second].first = p[x].first;

            if (d[p[x].second] != 0)
                q.push_back(p[x].second);
        }
        for (const size_t x : t) {
            if (p[x].first == -1)
                continue;

            p[p[x].first].second = p[x].second;

            if (d[p[x].first] != 0)
                q.push_back(p[x].first);
        }

        std::sort(q.begin(), q.end());
        q.erase(std::unique(q.begin(), q.end()), q.end());
    }

    answer(r);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), d(n);
    std::cin >> a >> d;

    solve(a, d);
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
