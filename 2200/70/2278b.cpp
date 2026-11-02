#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(unsigned x, unsigned y, unsigned z)
{
    answer(std::string(x + y + z, x >= y ? "SP"[x >= z] : "SR"[y >= z]));
}

void test_case()
{
    unsigned x, y, z;
    std::cin >> x >> y >> z;

    solve(x, y, z);
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
