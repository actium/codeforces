#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(int x, int y, int z, int t1, int t2, int t3)
{
    const int d1 = abs(x - y);
    const int d2 = abs(x - z);

    answer((d1 + d2) * t2 + 3 * t3 <= d1 * t1);
}

int main()
{
    int x, y, z, t1, t2, t3;
    std::cin >> x >> y >> z >> t1 >> t2 >> t3;

    solve(x, y, z, t1, t2, t3);

    return 0;
}

