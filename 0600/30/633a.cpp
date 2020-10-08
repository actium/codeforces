#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(unsigned a, unsigned b, unsigned c)
{
    for (unsigned x = 0; a * x <= c; ++x) {
        const unsigned d = c - a * x;
        if (d % b == 0)
            return answer(true);
    }

    answer(false);
}

int main()
{
    unsigned a, b, c;
    std::cin >> a >> b >> c;

    solve(a, b, c);

    return 0;
}

