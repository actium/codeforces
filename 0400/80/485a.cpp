#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(unsigned x, unsigned m)
{
    for (unsigned i = 0; i < m; ++i) {
        if (x % m == 0)
            return answer(true);

        x += x % m;
    }

    answer(false);
}

int main()
{
    unsigned x, m;
    std::cin >> x >> m;

    solve(x, m);

    return 0;
}
