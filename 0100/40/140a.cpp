#include <iostream>

#include <cmath>

const double pi = std::acos(-1), epsilon = 1e-15;

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned n, unsigned r1, unsigned r2)
{
    if (n == 1)
        return answer(r1 >= r2);

    if (r1 <= r2)
        return answer(false);

    answer((r1 - r2) * std::sin(pi / n) + epsilon >= r2);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, r1, r2;
    std::cin >> n >> r1 >> r2;

    solve(n, r1, r2);

    return 0;
}
