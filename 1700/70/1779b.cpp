#include <iostream>
#include <vector>

void answer(const std::vector<int>& v)
{
    std::cout << "YES" << '\n';

    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(unsigned n)
{
    if (n == 3)
        return no_answer();

    std::vector<int> s(n, n / 2);
    for (unsigned i = 0; i < n; i += 2)
        s[i] = n / 2 - n % 2;
    for (unsigned i = 1; i < n; i += 2)
        s[i] = -(n / 2);

    answer(s);
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
