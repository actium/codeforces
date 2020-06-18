#include <iostream>

size_t digit_sum(unsigned n)
{
    size_t sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned a)
{
    while (digit_sum(a) % 4 != 0)
        ++a;

    answer(a);
}

int main()
{
    unsigned a;
    std::cin >> a;

    solve(a);

    return 0;
}

