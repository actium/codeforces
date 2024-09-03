#include <iostream>
#include <vector>

using integer = unsigned long long;

std::vector<std::pair<integer, unsigned>> factorize(integer x)
{
    std::vector<std::pair<integer, unsigned>> factors;
    {
        for (integer i = 2; i * i <= x; ++i) {
            if (x % i != 0)
                continue;

            factors.emplace_back(i, 0);
            while (x % i == 0) {
                ++factors.back().second;
                x /= i;
            }
        }

        if (x != 1)
            factors.emplace_back(x, 1);
    }
    return factors;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(integer n, integer b)
{
    integer x = ~integer(0);
    for (const std::pair<integer, unsigned>& p : factorize(b)) {
        integer e = 0;
        for (integer x = n; x != 0; x /= p.first)
            e += x / p.first;

        x = std::min(x, e / p.second);
    }

    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    integer n, b;
    std::cin >> n >> b;

    solve(n, b);

    return 0;
}