#include <iostream>
#include <string>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.size();

    s.push_back(s[0]);

    unsigned f[2] = {}, g[2] = {};
    for (size_t i = 0; i < n; ++i) {
        f[i%2] += s[i] - '0';
        g[i%2] += (s[i] == '1' && s[i+1] == '1');
    }

    answer(f[0] + g[1] - g[0], f[1] + g[0] - g[1]);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    solve(s);
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
