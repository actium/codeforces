#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(size_t n, size_t count100, size_t count200)
{
    if (n == 1)
        return answer(false);

    if (count200 % 2 == 0)
        return answer(count100 % 2 == 0);

    answer(count100 >= 2 && count100 % 2 == 0);
}

int main()
{
    size_t n;
    std::cin >> n;

    size_t count100 = 0, count200 = 0;
    for (size_t i = 0; i < n; ++i) {
        size_t w;
        std::cin >> w;

        if (w == 100)
            ++count100;
        else
            ++count200;
    }

    solve(n, count100, count200);

    return 0;
}

