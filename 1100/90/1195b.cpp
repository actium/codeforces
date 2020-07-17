#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned k)
{
    long long ub = n+1;
    for (long long lb = -1; ub - lb > 1; ) {
        const long long mid = lb + (ub - lb) / 2;

        const long long q = (n - mid) * (n - mid + 1) / 2;
        if (q - mid > k)
            lb = mid;
        else
            ub = mid;
    }

    answer(ub);
}

int main()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}

