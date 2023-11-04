#include <iostream>

using integer = unsigned long long;

void answer(integer x, integer y)
{
    std::cout << x << ' ' << y << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned n)
{
    if (n == 1 || n == 2)
        return no_answer();

    if (n % 4 == 0)
        return answer(n / 4 * 3, n / 4 * 5);

    if (n % 2 == 0) {
        const integer a = n / 2, b = a * a - 1;
        answer(b, b + 2);
    } else {
        const integer a = n, b = a * a / 2;
        answer(b, b + 1);
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    integer n;
    std::cin >> n;

    solve(n);

    return 0;
}
