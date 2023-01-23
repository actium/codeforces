#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    const size_t n = s.length(), m = t.length();

    const auto next = [&](size_t b) {
        const size_t x = s.find(t, b);
        return x != std::string::npos ? x : n;
    };

    unsigned k = 0;
    for (size_t i = 0, x = next(0); i < n; ++i) {
        k += std::min(x - i + m - 1, n - i);
        if (i == x)
            x = next(x + 1);
    }

    answer(k);
}

void test_case()
{
    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
