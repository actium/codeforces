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

void solve(const std::vector<std::vector<size_t>>& g)
{
    const size_t n = g.size();

    std::vector<bool> v(n);
    size_t z = n;
    for (size_t i = 0; i < n; ++i) {
        const auto it = std::find_if(g[i].cbegin(), g[i].cend(), [&v](size_t x) { return !v[x-1]; });
        if (it != g[i].cend()) {
            v[*it - 1] = true;
        } else {
            z = i;
        }
    }

    if (z == n) {
        std::cout << "OPTIMAL" << '\n';
    } else {
        std::cout << "IMPROVE" << '\n';

        const auto y = std::find(v.cbegin(), v.cend(), false) - v.cbegin();
        std::cout << 1+z << ' ' << 1+y << '\n';
    }
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<size_t>> g(n);
    for (size_t i = 0; i < n; ++i) {
        size_t m;
        std::cin >> m;

        g[i].resize(m);
        std::cin >> g[i];
    }

    solve(g);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

