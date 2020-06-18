#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned x)
{
     answer((x + 4) / 5);
}

int main()
{
    unsigned x;
    std::cin >> x;

    solve(x);

    return 0;
}

