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

void solve(unsigned n, unsigned k)
{
    std::vector<unsigned> p;

    const unsigned c = 2 * k + 1;
    if (c >= n) {
        p.push_back(std::min(k + 1, n));
    } else {
        const unsigned d = (c - n % c) % c;
        for (unsigned i = k + 1 - d / 2; i <= n; i += c)
            p.push_back(i);
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

