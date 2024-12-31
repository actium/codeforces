#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned n, unsigned d)
{
    std::vector<unsigned> s = { 1 };
    if (d % 3 == 0 || n >= 3)
        s.push_back(3);
    if (d == 5)
        s.push_back(5);
    if (d == 7 || n >= 3)
        s.push_back(7);
    if (d == 9 || d % 3 == 0 && n >= 3 || n >= 6)
        s.push_back(9);

    answer(s);
}

void test_case()
{
    unsigned n, d;
    std::cin >> n >> d;

    solve(n, d);
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
