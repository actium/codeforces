#include <algorithm>
#include <iostream>
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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void traverse(const std::vector<std::vector<unsigned>>& g, size_t x, std::vector<bool>& v, std::vector<unsigned>& c)
{
    c.push_back(1 + x);
    v[x] = true;

    for (const size_t y : g[x]) {
        if (!v[y])
            traverse(g, y, v, c);
    }
}

std::vector<unsigned> cc(const std::vector<std::vector<unsigned>>& g, size_t x, std::vector<bool>& v)
{
    std::vector<unsigned> c;
    if (!v[x])
        traverse(g, x, v, c);

    return c;
}

void solve(size_t n, const std::vector<std::pair<unsigned, unsigned>>& e, std::vector<unsigned>& a)
{
    std::vector<std::vector<unsigned>> g(n);
    for (const auto& x : e) {
        g[x.first-1].push_back(x.second - 1);
        g[x.second-1].push_back(x.first - 1);
    }

    std::sort(a.begin(), a.end());

    const auto check = [&](const std::vector<unsigned>& c) {
        const unsigned k = std::count_if(c.begin(), c.end(), [&](unsigned x) {
            return std::binary_search(a.begin(), a.end(), x);
        });

        return k == 0 || k == c.size();
    };

    std::vector<bool> v(n);
    for (size_t i = 0; i < n; ++i) {
        if (!check(cc(g, i, v)))
            return answer(false);
    }

    answer(true);
}

void test_case()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<unsigned> a(k);
    std::cin >> a;

    std::vector<std::pair<unsigned, unsigned>> e(m);
    std::cin >> e;

    solve(n, e, a);
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
