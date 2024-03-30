#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    unsigned a = 0, b = 0;
    for (const char c : std::to_string(n)) {
        a = a * 10 + (c - '0');
        std::swap(a, b);
    }

    if (a == 0)
        return answer(b - 1);

    if (b == 0)
        return answer(a - 1);

    answer((a + 1) * (b + 1) - 2);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
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
