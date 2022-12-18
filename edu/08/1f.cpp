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

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    std::cout << v.size() << '\n';
    for (const std::pair<unsigned, unsigned> x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<size_t> o(n);
    for (size_t i = 0; i < n; ++i)
        o[i] = i;

    const auto sort = [&] {
        std::sort(o.begin(), o.end(), [&a](size_t x, size_t y) {
            return a[x] > a[y];
        });
    };

    std::vector<std::pair<unsigned, unsigned>> e;
    for (sort(); a[o.front()] != 0; sort()) {
        const size_t u = o[0];
        for (size_t i = 0; i < a[u]; ++i) {
            const size_t v = o[1 + i];
            e.emplace_back(1 + u, 1 + v);
            --a[v];
        }
        a[u] = 0;
    }

    answer(e);
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
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
