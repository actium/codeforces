#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    size_t c;

    if (n < 11 || n > 21) {
        c = 0;
    } else if (n < 20 || n == 21) {
        c = 4;
    } else  {
        c = 15;
    }

    answer(c);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

