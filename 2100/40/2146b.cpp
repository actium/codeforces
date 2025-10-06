#include <iostream>
#include <vector>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& s, unsigned m)
{
    std::vector<unsigned> f(1+m);
    for (const std::vector<unsigned>& v : s) {
        for (const unsigned x : v)
            ++f[x];
    }

    for (unsigned i = 1; i <= m; ++i) {
        if (f[i] == 0)
            return answer(false);
    }

    unsigned k = s.size();
    for (const std::vector<unsigned>& v : s) {
        for (const unsigned x : v) {
            if (f[x] == 1) {
                --k;
                break;
            }
        }
    }

    answer(k > 1);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    std::vector<std::vector<unsigned>> s(n);
    for (size_t i = 0; i < n; ++i) {
        size_t l;
        std::cin >> l;

        s[i].resize(l);
        for (size_t j = 0; j < l; ++j)
            std::cin >> s[i][j];
    }

    solve(s, m);
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
