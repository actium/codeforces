#include <algorithm>
#include <iostream>
#include <vector>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    std::vector<size_t> p(n + 1);
    for (size_t i = 2; i <= n; ++i) {
        if (p[i] != 0)
            continue;

        for (size_t j = i; j <= n; j += i)
            ++p[j];
    }

    answer(std::count(p.cbegin(), p.cend(), 2));
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

