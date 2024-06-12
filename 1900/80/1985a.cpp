#include <iostream>
#include <string>

void answer(const std::string& x, const std::string& y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(std::string& a, std::string& b)
{
    std::swap(a[0], b[0]);

    answer(a, b);
}

void test_case()
{
    std::string a, b;
    std::cin >> a >> b;

    solve(a, b);
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
