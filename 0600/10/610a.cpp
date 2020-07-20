#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    if (n % 2 != 0)
        return answer(0);

    answer(n / 4 - (n % 4 == 0));
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

