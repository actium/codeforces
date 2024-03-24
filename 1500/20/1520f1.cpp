#include <iostream>

unsigned query(unsigned lb, unsigned ub)
{
    std::cout << '?' << ' '  << lb << ' ' << ub << std::endl;

    unsigned r;
    std::cin >> r;
    return r;
}

void answer(unsigned x)
{
    std::cout << '!' << ' ' << x << std::endl;
}

void solve(size_t n, size_t t)
{
    while (t-- > 0) {
        unsigned k;
        std::cin >> k;

        size_t lb = 0, ub = n;
        while (lb + 1 < ub) {
            const size_t mid = (lb + ub) / 2;

            const unsigned q = query(lb + 1, mid), z = (mid - lb) - q;
            if (z < k) {
                lb = mid;
                k -= z;
            } else {
                ub = mid;
            }
        }

        answer(ub);
    }
}

int main()
{
    size_t n, t;
    std::cin >> n >> t;

    solve(n, t);

    return 0;
}
