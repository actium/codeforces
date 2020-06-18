#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t n, size_t k)
{
    size_t lb = 1;
    for (size_t ub = n + 1; lb < ub; ) {
        const size_t m = lb + (ub - lb) / 2;

        const size_t s = 5 * m * (m + 1) / 2;
        if (s + k <= 240)
            lb = m + 1;
        else
            ub = m;
    }

    answer(lb - 1);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}

