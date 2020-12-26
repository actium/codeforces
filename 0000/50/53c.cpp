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
    std::vector<unsigned> p(n);
    for (size_t i = 0; i < n; i += 2) {
        p[i+0] = 1 + i/2;
        p[i+1] = n - i/2;
    }

    answer(p);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

