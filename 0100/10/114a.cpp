#include <iostream>

void no_answer()
{
    std::cout << "NO" << '\n';
}

void answer(unsigned v)
{
    std::cout << "YES" << '\n';
    std::cout << v << '\n';
}

void solve(unsigned k, unsigned l)
{
    unsigned p = 0;
    while (l % k == 0)
        l /= k, ++p;

    if (l == 1)
        answer(p-1);
    else
        no_answer();
}

int main()
{
    unsigned k, l;
    std::cin >> k >> l;

    solve(k, l);

    return 0;
}

