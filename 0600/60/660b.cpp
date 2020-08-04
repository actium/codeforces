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

void solve(unsigned n, unsigned m)
{
    std::vector<unsigned> p;
    const auto push = [&](unsigned x) {
        if (p.size() < m && x <= m)
            p.push_back(x);
    };

    for (unsigned i = 0; i < n; ++i) {
        push(1 + 2*i + 2*n);
        push(1 + 2*i);
        push(2 + 2*i + 2*n);
        push(2 + 2*i);
    }

    answer(p);
}

int main()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}

