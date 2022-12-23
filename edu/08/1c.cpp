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

void answer(const char* v)
{
    std::cout << v << '\n';
}

void solve(size_t n, const std::vector<std::pair<unsigned, unsigned>>& e, const std::vector<unsigned>& a)
{
    const size_t k = a.size();

    std::vector<std::vector<unsigned>> g(n);
    for (const auto& x : e) {
        g[x.first-1].push_back(x.second - 1);
        g[x.second-1].push_back(x.first - 1);
    }

    for (size_t i = 0; i < n; ++i)
        std::sort(g[i].begin(), g[i].end());

    for (size_t i = 1; i < k; ++i) {
        const size_t u = a[i-1] - 1, v = a[i] - 1;
        if (!std::binary_search(g[u].begin(), g[u].end(), v))
            return answer("none");
    }

    const auto simple_path = [&](size_t lb) {
        std::vector<bool> v(n);
        for (size_t i = lb; i < k; ++i) {
            const unsigned u = a[i] - 1;
            if (v[u])
                return false;

            v[u] = true;
        }
        return true;
    };

    if (a.back() == a.front()) {
        answer(simple_path(1) ? "simple cycle" : "cycle");
    } else {
        answer(simple_path(0) ? "simple path" : "path");
    }
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
