#include <iostream>
#include <numeric>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(int n)
{
    if (n < 3)
        return answer(n);

    integer x = 0;
    for (int a = std::max(1, n - 7); a <= n; ++a) {
        for (int b = std::max(1, a - 7); b < a; ++b) {
            const integer u = std::lcm<integer>(a, b);

            for (int c = std::max(1, b - 7); c < b; ++c)
                x = std::max(x, std::lcm<integer>(u, c));
        }
    }

    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
