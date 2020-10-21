#include <iostream>
#include <vector>

void answer(unsigned k, const std::vector<unsigned>& v)
{
    std::cout << k << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned n)
{
    std::vector<unsigned> c(n, 1);
    unsigned k = 1;
    for (unsigned x = 2; x <= n+1; ++x) {
        if (c[x-2] == 2)
            continue;

        for (unsigned y = x * x; y <= n+1; y += x) {
            c[y-2] = 2;
            k = 2;
        }
    }

    answer(k, c);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

