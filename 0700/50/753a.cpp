#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    std::cout << v.size() << '\n';

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
    for (unsigned i = 1; i <= n; ++i) {
        c.push_back(i);
        n -= i;
    }
    c.back() += n;

    answer(c);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

