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
    std::vector<unsigned> v;

    if (n > 3) {
        for (unsigned x = 2; x <= n; x += 2)
            v.push_back(x);
    }

    for (unsigned x = 1; x <= n; x += 2)
        v.push_back(x);

    answer(v);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

