#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned n)
{
    const auto is_even = [](char c) {
        return (c - '0') % 2 == 0;
    };

    const std::string s = std::to_string(n);
    if (is_even(s.back()))
        return answer(0);

    if (is_even(s.front()))
        return answer(1);

    for (const char c : s) {
        if (is_even(c))
            return answer(2);
    }

    no_answer();
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
