#include <iostream>
#include <string>

void answer(size_t b1, size_t e1, size_t b2, size_t e2)
{
    std::cout << 1+b1 << ' ' << e1 << ' ' << 1+b2 << ' ' << e2 << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length(), x = s.find('0'), m = n - x;

    if (x == std::string::npos)
        return answer(0, n, 0, 1);

    const auto evaluate = [&](size_t b) {
        std::string t = s;
        for (size_t i = 0, d = n - m; i < m; ++i)
            t[d+i] ^= s[b+i] - '0';

        return t;
    };

    std::pair<std::string, size_t> best = { evaluate(0), 0 };
    for (size_t i = 1; i + m <= n; ++i)
        best = std::max(best, std::make_pair(evaluate(i), i));

    answer(0, n, best.second, best.second + m);
}

void test_case()
{
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
