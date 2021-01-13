#include <iostream>
#include <set>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned lb, unsigned ub)
{
    unsigned k = 0;

    std::set<unsigned long long> q = { 1 };
    for (const unsigned x : q) {
        if (x * 2 <= ub)
            q.insert(x * 2);

        if (x * 3 <= ub)
            q.insert(x * 3);

        if (x >= lb)
            ++k;
    }

    answer(k);
}

int main()
{
    unsigned lb, ub;
    std::cin >> lb >> ub;

    solve(lb, ub);

    return 0;
}

