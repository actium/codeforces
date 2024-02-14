#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

auto count(unsigned b, unsigned h)
{
    return h >= b ? b * (b + 1ull) / 2 + 1ull * b * (h - b) : (h - 1ull) * h / 2 + b;
}

void solve(unsigned n, unsigned m, unsigned k)
{
    const auto check = [=](unsigned x) {
        return count(k - 1, x - 1) + x + count(n - k, x - 1) <= m;
    };

    unsigned lb = 1, ub = m + 1;
    while (lb + 1 < ub) {
        const unsigned mid = (lb + ub) / 2;
        (check(mid) ? lb : ub) = mid;
    }

    answer(lb);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, m, k;
    std::cin >> n >> m >> k;

    solve(n, m, k);

    return 0;
}
