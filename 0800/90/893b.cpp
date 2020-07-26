#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    for (const unsigned x : { 32640, 8128, 2016, 496, 120, 28, 6, 1 }) {
        if (n % x == 0)
            return answer(x);
    }
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

