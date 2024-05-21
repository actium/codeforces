#include <iostream>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned m)
{
    using integer = unsigned long long;

    std::vector<unsigned> t(1 + n);
    t[0] = 1;
    for (integer i = 1; i <= n; ++i)
        t[i] = t[i-1] * i % m;

    unsigned k = 0;
    for (integer i = 0; i < n; ++i) {
        integer x = (n - i) * (n - i) % m;
        x = x * t[i+1] % m;
        x = x * t[n-1-i] % m;
        k = (k + x) % m;
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}
