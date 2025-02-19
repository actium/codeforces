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
        std::cout << 1+x.first << ' ' << 1+x.second << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::set<size_t> q[3];
    for (size_t i = 0; i < n; ++i)
        q[a[i]].insert(i);

    std::vector<std::pair<size_t, size_t>> p;

    const auto swap = [&](size_t x) {
        const size_t y = *q[a[x]-1].rbegin();

        p.emplace_back(x, y);
        q[a[x]].erase(x);
        q[a[x]].insert(y);
        q[a[y]].erase(y);
        q[a[y]].insert(x);

        std::swap(a[x], a[y]);
    };

    size_t x = 0;
    for (const size_t m = x + q[0].size(); x < m; ++x) {
        while (a[x] != 0)
            swap(x);
    }
    for (const size_t m = x + q[1].size(); x < m; ++x) {
        while (a[x] != 1)
            swap(x);
    }

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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
