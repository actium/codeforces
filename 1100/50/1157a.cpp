#include <iostream>
#include <set>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

unsigned f(unsigned x)
{
    for (++x; x % 10 == 0; x /= 10);
    return x;
}

void solve(unsigned n)
{
    unsigned k = 0;
    for (std::set<unsigned> s; s.count(n) == 0; n = f(n)) {
        s.insert(n);
        ++k;
    }

    answer(k);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

