#include <iostream>
#include <vector>

using integer = unsigned long long;

void answer(const std::vector<unsigned>& v)
{
    std::cout << "YES" << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(unsigned n, unsigned k, integer s)
{
    if (k > s)
        return no_answer();

    integer d = (s + k - 1) / k;
    if (d >= n)
        return no_answer();

    std::vector<unsigned> p(k);
    for (unsigned i = 0, x = 1; i < k; ++i) {
        d = (s + (k - i) - 1) / (k - i);
        x = (i % 2 == 0 ? x + d : x - d);
        p[i] = x;
        s -= d;
    }

    answer(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, k;
    std::cin >> n >> k;

    integer s;
    std::cin >> s;

    solve(n, k, s);

    return 0;
}
