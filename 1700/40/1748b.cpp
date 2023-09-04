#include <iostream>
#include <string>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    const auto count = [&](size_t x) {
        unsigned f[10] = {}, u = 0, q = 0, k = 0;
        for (size_t i = 0; i < 100 && x + i < n; ++i) {
            const unsigned d = s[x+i] - '0';
            if (f[d]++ == 0)
                ++u;

            q = std::max(q, f[d]);
            k += (q <= u);
        }
        return k;
    };

    integer k = 0;
    for (size_t i = 0; i < n; ++i)
        k += count(i);

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
