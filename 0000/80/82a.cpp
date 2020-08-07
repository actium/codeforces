#include <iostream>

void answer(size_t v)
{
    constexpr const char* s[5] = { "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };
    std::cout << s[v] << '\n';
}

void solve(unsigned n)
{
    unsigned d = 1, i = 1;
    while (d + 5 * i <= n) {
        d += 5 * i;
        i *= 2;
    }

    answer((n - d) / i);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

