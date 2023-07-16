#include <iostream>
#include <map>
#include <vector>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& c)
{
    const size_t n = c.size();

    std::map<unsigned, unsigned> f;
    for (const std::vector<unsigned>& v : c) {
        for (const unsigned x : v)
            ++f[x];
    }

    const auto check = [&](const std::vector<unsigned>& v) {
        for (const unsigned x : v) {
            if (f[x] == 1)
                return false;
        }
        return true;
    };

    for (const std::vector<unsigned>& v : c) {
        if (check(v))
            return answer(true);
    }

    answer(false);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<unsigned>> c(n);
    for (size_t i = 0; i < n; ++i) {
        size_t k;
        std::cin >> k;

        c[i].resize(k);
        for (size_t j = 0; j < k; ++j)
            std::cin >> c[i][j];
    }

    solve(c);
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
