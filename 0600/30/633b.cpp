#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    std::cout << v.size();

    const char* separator = "\n";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned m)
{
    std::vector<unsigned> p;
    for (unsigned x = 1, k = 0; k <= m; ++x) {
        for (unsigned q = x; q % 5 == 0; q /= 5)
            ++k;

        if (k == m)
            p.push_back(x);
    }

    answer(p);
}

int main()
{
    unsigned m;
    std::cin >> m;

    solve(m);

    return 0;
}

