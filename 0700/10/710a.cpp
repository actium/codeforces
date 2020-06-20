#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(char c, char d)
{
    if (c > 'a' && c < 'h' && d > '1' && d < '8')
        return answer(8);

    if (c > 'a' && c < 'h' || d > '1' && d < '8')
        return answer(5);

    answer(3);
}

int main()
{
    char c, d;
    std::cin >> c >> d;

    solve(c, d);

    return 0;
}

