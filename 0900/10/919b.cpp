#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

bool test(unsigned n)
{
    unsigned s = 0;
    while (n != 0 && s < 11) {
        s += n % 10;
        n /= 10;
    }
    return s == 10;
}

void solve(unsigned k)
{
    unsigned x = 2;
    while (!test(x * 9 + 1) || --k > 0)
        ++x;

    answer(x * 9 + 1);
}

int main()
{
    unsigned k;
    std::cin >> k;

    solve(k);

    return 0;
}

