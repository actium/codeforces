#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned long long k)
{
    unsigned v = 1;
    while (k % 2 == 0) {
        ++v;
        k /= 2;
    }

    answer(v);
}

int main()
{
    unsigned n;
    std::cin >> n;

    unsigned long long k;
    std::cin >> k;

    solve(n, k);

    return 0;
}

