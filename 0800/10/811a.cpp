#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "Vladik", "Valera" };
    std::cout << s[v] << '\n';
}

void solve(size_t a, size_t b)
{
    size_t x = 1;
    while (x <= a && x+1 <= b) {
        a -= x;
        b -= x+1;
        x += 2;
    }

    answer(x <= a);
}

int main()
{
    size_t a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}

