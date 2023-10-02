#include <iostream>
#include <vector>

using integer = unsigned long long;

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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::pair<int, int>>& c, size_t k, size_t a, size_t b)
{
    const size_t n = c.size();

    const auto distance = [&](size_t u, size_t v) -> integer {
        return llabs(c[u].first - c[v].first) + llabs(c[u].second - c[v].second);
    };

    const auto d = [&](size_t x) {
        if (x < k)
            return 0ull;

        integer d = ~0ull;
        for (size_t i = 0; i < k; ++i) {
            if (i != x)
                d = std::min(d, distance(x, i));
        }
        return d;
    };

    answer(std::min(distance(a, b), d(a) + d(b)));
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    unsigned a, b;
    std::cin >> a >> b;

    std::vector<std::pair<int, int>> c(n);
    std::cin >> c;

    solve(c, k, a - 1, b - 1);
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
