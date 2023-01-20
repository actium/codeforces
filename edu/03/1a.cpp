#include <iostream>
#include <vector>

void answer(size_t x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    const auto check = [&s](size_t k) {
        for (size_t i = 0, j = k - 1; i < j; ++i, --j) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    };

    size_t x = 1;
    for (size_t k = 2; k <= n; ++k) {
        if (check(k))
            x = k;
    }

    answer(x);
}

void test_case()
{
    std::string s;
    std::cin >> s;

    solve(s);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
