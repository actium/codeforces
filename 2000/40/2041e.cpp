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

void solve(int a, int b)
{
    std::vector<int> v(3, b);
    v[a < b ? 2 : 0] = 3 * a - 2 * b;
    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}
