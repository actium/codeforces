#include <iostream>
#include <vector>

void answer(unsigned u, const std::vector<int>& v)
{
    std::cout << u << '\n';

    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned x, unsigned y)
{
    std::vector<int> s;
    s.insert(s.end(), y, -1);
    s.insert(s.end(), x, 1);

    const unsigned d = std::max(x, y) - std::min(x, y);

    unsigned k = 1;
    for (unsigned s = 2; s <= d; ++s)
        k += (d % s == 0);

    answer(k, s);
}

void test_case()
{
    unsigned x, y;
    std::cin >> x >> y;

    solve(x, y);
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
