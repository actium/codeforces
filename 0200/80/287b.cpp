#include <iostream>

using integer = unsigned long long;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(integer n, unsigned k)
{
    if (n == 1)
        return answer(0);

    const auto check = [=](unsigned q) {
        return (2ull * k - q + 1) * q / 2 - (q - 1) >= n;
    };

    if (!check(k))
        return no_answer();

    int lb = 0, ub = k;
    while (lb + 1 < ub) {
        const int mid = (lb + ub) / 2;
        (check(mid) ? ub : lb) = mid;
    }

    answer(ub);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    integer n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    solve(n, k);

    return 0;
}