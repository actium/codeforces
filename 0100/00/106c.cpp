#include <iostream>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

struct Option {
    unsigned a;
    unsigned b;
    unsigned c;
    unsigned d;
};

void solve(unsigned n, unsigned c0, unsigned d0, const std::vector<Option>& s)
{
    std::vector<unsigned> dp(1+n);
    for (unsigned k = 1; k <= n / c0; ++k)
        dp[c0 * k] = d0 * k;

    for (const Option& o : s) {
        for (unsigned k = o.a / o.b; k != 0; --k) {
            for (unsigned x = n; x > o.c; --x) {
                if (dp[x-o.c] != 0)
                    dp[x] = std::max(dp[x], dp[x-o.c] + o.d);
            }
            dp[o.c] = std::max(dp[o.c], o.d);
        }
    }

    unsigned v = 0;
    for (const unsigned x : dp)
        v = std::max(v, x);

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, m, c0, d0;
    std::cin >> n >> m >> c0 >> d0;

    std::vector<Option> s(m);
    for (Option& x : s)
        std::cin >> x.a >> x.b >> x.c >> x.d;

    solve(n, c0, d0, s);

    return 0;
}
