#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::string& x)
{
    const size_t n = x.length();

    const auto d = [](char c) {
        return c - '0';
    };

    for (size_t i = n - 1; i > 0; --i) {
        const unsigned a = d(x[i-1]), b = d(x[i]);
        if (a + b >= 10) {
            x[i-1] = '1';
            x[i] += a - 10;
            return answer(x);
        }
    }

    x[1] += d(x[0]);
    answer(x.substr(1));
}

void test_case()
{
    std::string x;
    std::cin >> x;

    solve(x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
