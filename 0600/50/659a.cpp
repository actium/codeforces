#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(int n, int a, int b)
{
    answer(1 + (a-1 + n + b % n) % n);
}

int main()
{
    int n, a, b;
    std::cin >> n >> a >> b;

    solve(n, a, b);

    return 0;
}

