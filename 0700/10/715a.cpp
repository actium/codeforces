#include <iostream>
#include <vector>

using integer = unsigned long long;

void answer(const std::vector<integer>& v)
{
    for (const integer x : v)
        std::cout << x << '\n';
}

void solve(unsigned n)
{
    std::vector<integer> c(n);
    c[0] = 2;
    for (integer i = 2; i <= n; ++i)
        c[i-1] = i * (i + 1) * (i + 1) - (i - 1);

    answer(c);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
