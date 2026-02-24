#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(int x, int y)
{
    if (y < 0)
        return answer(-y * 4 <= x && (x + y * 4) % 3 == 0);

    if (y > 0)
        return answer(y * 2 <= x && (x - y * 2) % 3 == 0);

    answer(x % 3 == 0);
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
