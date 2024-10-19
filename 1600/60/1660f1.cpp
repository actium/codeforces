#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        unsigned f[2] = {}, p = 0, z = 0;
        for (size_t j = i; j < n; ++j) {
            if (s[j] == '+') {
                ++f[0];
                z = 0;
            } else {
                ++f[1];
                p += z;
                z = (z + 1) % 2;
            }

            if (f[0] <= f[1] && f[0] + p >= f[1] - 2 * p && (f[1] - f[0]) % 3 == 0)
                ++k;
        }
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

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
