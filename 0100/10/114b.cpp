#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::string>& v)
{
    std::cout << v.size() << '\n';

    for (const std::string& x : v)
        std::cout << x << '\n';
}

void solve(const std::vector<std::string>& s, const std::vector<std::vector<bool>>& p)
{
    const size_t n = s.size(), ub = 1 << n;

    const auto check = [&](unsigned x) {
        for (unsigned i = 0; i < n; ++i) {
            if ((x & 1 << i) == 0)
                continue;

            for (unsigned j = 0; j < n; ++j) {
                if ((x & 1 << j) != 0 && p[i][j])
                    return false;
            }
        }
        return true;
    };

    unsigned x = 0;
    for (unsigned i = 1; i < ub; ++i) {
        if (check(i) && __builtin_popcount(i) > __builtin_popcount(x))
            x = i;
    }

    std::vector<std::string> t;
    for (unsigned i = 0; i < n; ++i) {
        if ((x & 1 << i) != 0)
            t.push_back(s[i]);
    }

    std::sort(t.begin(), t.end());

    answer(t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n);
    std::cin >> s;

    const auto index = [&](const std::string& x) {
        return std::find(s.begin(), s.end(), x) - s.begin();
    };

    std::vector<std::vector<bool>> p(n, std::vector<bool>(n));
    for (size_t i = 0; i < m; ++i) {
        std::string a, b;
        std::cin >> a >> b;

        const size_t u = index(a), v = index(b);
        p[u][v] = true;
        p[v][u] = true;
    }

    solve(s, p);

    return 0;
}
