#include <iostream>

bool lucky(int n)
{
    while (n != 0) {
        if (abs(n % 10) == 8)
            return true;

        n /= 10;
    }
    return false;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(int a)
{
    unsigned b = 1;
    while (!lucky(a + b))
        ++b;

    answer(b);
}

int main()
{
    int a;
    std::cin >> a;

    solve(a);

    return 0;
}

