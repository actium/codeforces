#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned n)
{
    std::vector<unsigned> c;
    for (unsigned x = 2; x * x <= n; ++x) {
        while (n % x == 0) {
            c.push_back(n);
            n /= x;
        }
    }

    if (n != 1)
        c.push_back(n);

    c.push_back(1);

    answer(c);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

