#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned n)
{
    for (unsigned a = 0; a <= n; a += 1234567) {
        for (unsigned b = 0; a + b <= n; b += 123456) {
            if ((n - a - b) % 1234 == 0)
                return answer(true);
        }
    }

    answer(false);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

