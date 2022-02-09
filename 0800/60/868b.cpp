#include <algorithm>
#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned h, unsigned m, unsigned s, unsigned t1, unsigned t2)
{
    unsigned t[] = { h * 10 + 1, m * 2 + 1, s * 2 + 1, t1 * 10, t2 * 10 };

    std::sort(std::begin(t), std::end(t));

    for (size_t i = 0; i < 5; ++i) {
        if (t[i] % 2 == 0 && t[(i+1)%5] % 2 == 0)
            return answer(true);
    }

    answer(false);
}

int main()
{
    unsigned h, m, s;
    std::cin >> h >> m >> s;

    unsigned t1, t2;
    std::cin >> t1 >> t2;

    solve(h, m, s, t1, t2);

    return 0;
}
