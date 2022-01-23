#include <algorithm>
#include <iostream>
#include <vector>

unsigned query(unsigned i, unsigned j)
{
    std::cout << "? " << i << ' ' << j << std::endl;

    unsigned r;
    std::cin >> r;
    return r;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "! ";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << std::endl;
}

void solve()
{
    const unsigned r[4] = { query(1, 2), query(2, 3), query(4, 5), query(5, 6) };

    std::vector<unsigned> p = { 4, 8, 15, 16, 23, 42 };
    while (p[0]*p[1] != r[0] || p[1]*p[2] != r[1] || p[3]*p[4] != r[2] || p[4]*p[5] != r[3])
        std::next_permutation(p.begin(), p.end());

    answer(p);
}

int main()
{
    solve();

    return 0;
}
