#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& a, const std::string& b, size_t k)
{
    const size_t n = a.length();

    unsigned fa[26] = {}, fb[26] = {};
    for (size_t i = 0; i < n; ++i) {
        ++fa[a[i]-'a'];
        ++fb[b[i]-'a'];
    }

    for (size_t i = 0; i < 25; ++i) {
        if (fa[i] < fb[i] || (fa[i] - fb[i]) % k != 0)
            return answer(false);

        fa[i+1] += fa[i] - fb[i];
    }

    answer(true);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::string a, b;
    std::cin >> a >> b;

    solve(a, b, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
