#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(integer w, integer m, integer k)
{
    std::pair<integer, unsigned> b = { 1, 0 };
    while (b.first <= m) {
        b.first *= 10;
        ++b.second;
    }

    integer q = 0;
    while (b.second * k <= w) {
        const integer d = b.first - (m + q);
        if (d * b.second * k <= w) {
            q += d;
            w -= d * b.second * k;
            b.first *= 10;
            ++b.second;
        } else {
            const integer e = w / (b.second * k);
            q += e;
            w -= e * b.second * k;
        }
    }

    answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    integer w, m, k;
    std::cin >> w >> m >> k;

    solve(w, m, k);

    return 0;
}
