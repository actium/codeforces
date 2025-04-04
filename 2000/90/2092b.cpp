#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& a, const std::string& b)
{
    const size_t n = a.size();

    unsigned f[2][2] = {};
    for (size_t i = 0; i < n; ++i) {
        f[0][i%2] += a[i] - '0';
        f[1][i%2] += '1' - b[i];
    }

    answer(f[0][0] <= f[1][1] && f[0][1] <= f[1][0]);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string a, b;
    std::cin >> a >> b;

    solve(a, b);
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
