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
    unsigned p = 1;
    while (p * p < n)
        ++p;

    std::vector<unsigned> s(n);
    for (unsigned i = 0; i < n; i += p) {
        for (unsigned j = 0, k = std::min(p, n - i); j < k; ++j)
            s[i+j] = i + k - j;
    }

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
