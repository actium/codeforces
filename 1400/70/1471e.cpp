#include <iostream>
#include <vector>

#include <cmath>

unsigned ask(size_t x)
{
    std::cout << "? " << 1+x << std::endl;

    unsigned r;
    std::cin >> r;
    return r;
}

void answer(size_t v)
{
    std::cout << "! " << 1+v << std::endl;
}

void solve(unsigned n, unsigned k)
{
    std::vector<size_t> l, r;
    for (size_t x = 0, d = sqrt(n) + 1; l.empty() || r.empty(); x = (x + d) % n) {
        const unsigned q = ask(x);
        if (q < k)
            l.push_back(x);
        if (q > k)
            r.push_back(x);
    }

    size_t lb = l.front(), ub = r.front();
    if (ub < lb)
        ub += n;

    while (true) {
        const size_t x = (lb + ub) / 2;

        const unsigned q = ask(x % n);
        if (q == k)
            return answer(x % n);

        if (q < k)
            lb = x;
        else
            ub = x;
    }
}

int main()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}

