#include <iostream>

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    if (n % 4 == 0)
        return answer(n / 4);

    if (n >= 6 && (n - 6) % 4 == 0)
        return answer(1 + (n - 6) / 4);

    if (n >= 9 && (n - 9) % 4 == 0)
        return answer(1 + (n - 9) / 4);

    if (n >= 15 && (n - 15) % 4 == 0)
        return answer(2 + (n - 15) / 4);

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

