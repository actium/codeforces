#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned n, int p)
{
    for (int k = 1; k < 32 && k * p <= int(n); ++k) {
        if (__builtin_popcount(n - k * p) <= k && n - k * p >= k)
            return answer(k);
    }

    no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    int p;
    std::cin >> p;

    solve(n, p);

    return 0;
}
