#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned m)
{
    const auto check = [=](unsigned k) {
        const unsigned u = k / 2, v = k / 3, w = k / 6;
        return u >= n && v >= m && u + v - w >= n + m;
    };

    unsigned lb = 0, ub = n * 2 + m * 3;
    while (lb + 1 < ub) {
        const unsigned mid = (lb + ub) / 2;
        (check(mid) ? ub : lb) = mid;
    }

    answer(ub);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}
