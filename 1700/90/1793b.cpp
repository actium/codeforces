#include <iostream>
#include <vector>

void answer(const std::vector<int>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(int x, int y)
{
    std::vector<int> a;
    a.reserve((x - y) * 2);

    for (int i = y; i < x; ++i)
        a.push_back(i);
    for (int i = x; i > y; --i)
        a.push_back(i);

    answer(a);
}

void test_case()
{
    int x, y;
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
