#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(size_t n, size_t k)
{
    const size_t m = k * k;

    std::string p = "a";
    {
        bool v[26][26] = {};
        for (size_t i = 0, x = 0; p.length() < m; i = (i + 1) % k) {
            if (!v[x][i]) {
                p.push_back('a' + i);
                v[x][i] = true;
                x = i--;
            }
        }
    }

    std::string s;
    for (size_t i = 0; i < n; ++i)
        s.push_back(p[i % m]);

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}
