#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<std::pair<size_t, size_t>>& v)
{
    for (const auto [l, r] : v)
        std::cout << 1+l << ' ' << 1+r << '\n';
}

void solve(const std::string& t)
{
    const size_t n = t.length(), k = n / 2;

    std::vector<std::pair<size_t, size_t>> p(k);
    for (size_t i = 0; i < k; ++i) {
        p[i] = { i, k + i };

        if (t[i] == 'R' && t[k+i] == 'L')
            std::swap(p[i].first, p[i].second);
    }

    answer(p);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    size_t n;
    std::cin >> n;

    std::string t;
    std::cin >> t;

    solve(t);

    return 0;
}

