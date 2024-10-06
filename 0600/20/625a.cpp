#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(integer n, integer a, integer b, integer c)
{
    if (a <= b - c || n < b)
        return answer(n / a);

    const integer k = (n - c) / (b - c);
    n -= k * (b - c);

    answer(k + n / a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    integer n, a, b, c;
    std::cin >> n >> a >> b >> c;

    solve(n, a, b, c);

    return 0;
}
