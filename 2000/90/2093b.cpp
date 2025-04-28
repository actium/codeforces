#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& n)
{
    const size_t x = n.find_last_not_of("0");

    unsigned k = n.size() - x;
    for (size_t i = 0; i < x; ++i)
        k += (n[i] != '0');

    answer(k - 1);
}

void test_case()
{
    std::string n;
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
