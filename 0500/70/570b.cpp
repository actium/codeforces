#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned m)
{
    if (n == 1)
        return answer(1);

    answer(m - 1 >= n - m ? m - 1 : m + 1);
}

int main()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}

