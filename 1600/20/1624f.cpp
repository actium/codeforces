#include <iostream>

unsigned query(unsigned x)
{
    std::cout << "+ " << x << std::endl;

    unsigned r;
    std::cin >> r;
    return r;
}

void answer(unsigned x)
{
    std::cout << "! " << x << std::endl;
}

void solve(unsigned n)
{
    unsigned lb = 1, ub = n, d = 0, v = 0;
    while (lb + 1 < ub) {
        const unsigned mid = (lb + ub) / 2;

        const unsigned c = (n - mid + n - d % n) % n;
        if (query(c) != v) {
            lb = mid;
            ++v;
        } else {
            ub = mid;
        }

        d += c;
    }

    answer(lb + d);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
