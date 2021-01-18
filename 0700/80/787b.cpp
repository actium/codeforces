#include <iostream>
#include <vector>

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

void solve(size_t n, const std::vector<std::vector<int>>& g)
{
    const auto check = [n](const std::vector<int>& r) {
        std::vector<int> x(1+n);
        for (const int q : r) {
            if (x[abs(q)] == -q)
                return true;

            x[abs(q)] = q;
        }
        return false;
    };

    for (const auto& r : g) {
        if (!check(r))
            return answer(true);
    }

    answer(false);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> g(m);
    for (size_t i = 0; i < m; ++i) {
        size_t k;
        std::cin >> k;

        g[i].resize(k);
        std::cin >> g[i];
    }

    solve(n, g);

    return 0;
}

