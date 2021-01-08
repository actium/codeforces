#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(unsigned x, unsigned y)
{
    if (x > 0 && y < 2)
        return answer(false);

    answer(y - 1 <= x && (x - y + 1) % 2 == 0);
}

int main()
{
    unsigned x, y;
    std::cin >> x >> y;

    solve(x, y);

    return 0;
}

