#include <iostream>

unsigned query(unsigned lb, unsigned ub)
{
    std::cout << "? " << lb << ' ' << ub << std::endl;

    unsigned p;
    std::cin >> p;
    return p;
}

void answer(unsigned x)
{
    std::cout << "! " << x << std::endl;
}

void solve(unsigned n)
{
    unsigned lb = 1, ub = n, x = query(1, n);
    while (lb + 1 < ub) {
        const unsigned mid = (lb + ub + 1) / 2;
        if (mid < x) {
            const unsigned p = query(mid, ub);
            if (p == x) {
                lb = mid;
            } else {
                ub = mid;
                x = query(lb, ub);
            }
        } else {
            const unsigned p = query(lb, mid);
            if (p == x) {
                ub = mid;
            } else {
                lb = mid;
                x = query(lb, ub);
            }
        }
    }

    answer(lb == x ? ub : lb);
}

int main()
{
    unsigned n;
    std::cin >> n;

    for (int i = 0; i < 20; ++i)
    solve(n);

    return 0;
}
