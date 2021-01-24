#include <iostream>
#include <set>
#include <vector>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned x)
{
    std::set<unsigned> f;
    for (unsigned i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            f.insert(i);
            f.insert(x / i);
        }
    }

    std::set<unsigned> d;
    while (x != 0) {
        d.insert(x % 10);
        x /= 10;
    }

    unsigned k = 0;
    for (unsigned q : f) {
        auto it = d.end();
        for ( ; q != 0 && it == d.end(); q /= 10)
            it = d.find(q % 10);

        k += (it != d.end());
    }

    answer(k);
}

int main()
{
    unsigned x;
    std::cin >> x;

    solve(x);

    return 0;
}

