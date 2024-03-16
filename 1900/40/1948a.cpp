#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << "YES" << '\n';
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(size_t n)
{
    if (n % 2 == 1)
        return no_answer();

    std::string s;
    for (size_t i = 0; i < n; i += 2) {
        s.push_back('A' + i % 26);
        s.push_back('A' + i % 26);
    }

    answer(s);
}

void test_case()
{
    size_t n;
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
