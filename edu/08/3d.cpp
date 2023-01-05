#include <iostream>
#include <set>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::set<size_t>& v)
{
    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1 + x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(size_t n, const std::vector<std::pair<unsigned, unsigned>>& e)
{
    std::vector<std::vector<size_t>> g(n);
    for (const std::pair<unsigned, unsigned>& q : e)
        g[q.first - 1].push_back(q.second - 1);

    for (size_t i = 0; i < n; ++i) {
        std::set<size_t> v;
        for (const size_t j : g[i])
            v.insert(g[j].begin(), g[j].end());

        answer(v);
    }
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::pair<unsigned, unsigned>> e(m);
    std::cin >> e;

    solve(n, e);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
