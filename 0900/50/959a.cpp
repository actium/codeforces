#include <iostream>

void answer(const char* v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    answer(n % 2 == 0 ? "Mahmoud" : "Ehab");
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

