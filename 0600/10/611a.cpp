#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned x, const std::string& y)
{
    if (y == "week")
        return answer(52 + (x > 4 && x < 7));

    if (x < 30)
        return answer(12);

    answer(x == 30 ? 11 : 7);
}

int main()
{
    unsigned x;
    char y[6];
    scanf("%u of %s", &x, y);

    solve(x, y);

    return 0;
}

