#include <iostream>

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(int n)
{
    if (n > 0)
        return answer(n);

    const int m = n / 10;
    if (-n % 10 > -m % 10)
        return answer(m);

    answer(m / 10 * 10 + n % 10);
}

int main()
{
    int n;
    std::cin >> n;

    solve(n);

    return 0;
}

