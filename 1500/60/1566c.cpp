#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& t1, const std::string& t2)
{
    const size_t n = t1.length();

    const auto mex = [](const std::vector<char>& a) {
        unsigned x = 0, y = 1;
        for (const char c : a) {
            x |= c - '0';
            y &= c - '0';
        }
        return (x + y + 1) % 3;
    };

    std::vector<unsigned> dp1(n), dp2(n);
    for (size_t i = 0; i < n; ++i) {
        if (i > 0)
            dp1[i] = std::max(dp1[i-1], dp2[i-1]);
        if (true)
            dp1[i] += mex({ t1[i], t2[i] });

        if (i > 1)
            dp2[i] = std::max(dp1[i-2], dp2[i-2]);
        if (i > 0)
            dp2[i] += mex({ t1[i-1], t2[i-1], t1[i], t2[i] });
    }

    answer(std::max(dp1.back(), dp2.back()));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string t1, t2;
    std::cin >> t1 >> t2;

    solve(t1, t2);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
