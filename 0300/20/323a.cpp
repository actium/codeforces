#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<std::string>& v)
{
    for (const std::string& x : v)
        std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(size_t k)
{
    if (k % 2 == 1)
        return no_answer();

    const size_t m = k / 2;

    std::vector<std::string> v(k, std::string(k, 'b'));
    for (size_t r = m % 2 + 1; r < m; r += 2) {
        for (size_t j = m - r; j < m + r; ++j) {
            v[m-r][j] = 'w';
            v[m+r-1][j] = 'w';
        }
        for (size_t i = m - r; i < m + r; ++i) {
            v[i][m-r] = 'w';
            v[i][m+r-1] = 'w';
        }
    }
    for (size_t i = 1; i < k; ++i) {
        for (size_t j = 0; j < k; ++j) {
            std::string s = v[v.size() - k];
            for (char& c : s)
                c ^= 'b' ^ 'w';

            v.push_back(s);
        }
    }

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t k;
    std::cin >> k;

    solve(k);

    return 0;
}
