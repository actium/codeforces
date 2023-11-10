#include <iostream>

void answer(unsigned x, unsigned y, unsigned z)
{
    std::cout << "YES" << '\n';
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(unsigned n)
{
    if (n % 3 == 0 && n > 9)
        return answer(1, 4, n - 5);

    if (n % 3 != 0 && n > 6)
        return answer(1, 2, n - 3);

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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
