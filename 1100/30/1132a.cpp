#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned c1, unsigned c3, unsigned c4)
{
    if (c1 != c4)
        return answer(false);

    answer(c3 == 0 || c1 > 0);
}

int main()
{
    unsigned c1, c2, c3, c4;
    std::cin >> c1 >> c2 >> c3 >> c4;

    solve(c1, c3, c4);

    return 0;
}

