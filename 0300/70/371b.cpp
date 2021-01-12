#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned a, unsigned b)
{
    constexpr unsigned d[3] = { 2, 3, 5 };

    unsigned f[2][3] = {}, k = 0;
    for (size_t i = 0; i < 3; ++i) {
        while (a % d[i] == 0) {
            a /= d[i];
            ++f[0][i];
        }
        while (b % d[i] == 0) {
            b /= d[i];
            ++f[1][i];
        }

        k += abs(f[0][i] - f[1][i]);
    }

    if (a != b)
        return no_answer();

    answer(k);
}

int main()
{
    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}

