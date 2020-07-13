#include <iostream>

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned m)
{
    if (m % n != 0)
        return answer(-1);

    unsigned k = 0;
    for (m /= n; m != 1; ++k) {
        if (m % 3 != 0 && m % 2 != 0)
            return answer(-1);

        m /= (m % 3 == 0 ? 3 : 2);
    }

    answer(k);
}

int main()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}

