#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned x, unsigned t, unsigned a, unsigned b, unsigned da, unsigned db)
{
    for (unsigned i = 0; i < t; ++i) {
        if (a - i * da == x)
            return answer(true);

        if (b - i * db == x)
            return answer(true);

        for (unsigned j = 0; j < t; ++j) {
            if (a - i * da + b - j * db == x)
                return answer(true);
        }
    }

    answer(x == 0);
}

int main()
{
    unsigned x, t, a, b, da, db;
    std::cin >> x >> t >> a >> b >> da >> db;

    solve(x, t, a, b, da, db);

    return 0;
}

