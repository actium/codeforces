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

void solve(unsigned n, unsigned k)
{
    std::vector<unsigned> p;
    for (unsigned i = 1; i <= n; ++i) {
        if (k > 0) {
            p.emplace_back(2 * i);
            p.emplace_back(2 * i - 1);
            --k;
        } else {
            p.emplace_back(2 * i - 1);
            p.emplace_back(2 * i);
        }
    }

    answer(p);
}

int main()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}
