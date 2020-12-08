#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned l, unsigned r, unsigned x, unsigned y, unsigned k)
{
    for (unsigned long long b = x; b <= y; ++b) {
        if (b * k >= l && b * k <= r)
            return answer(true);
    }

    answer(false);
}

int main()
{
    unsigned l, r, x, y, k;
    std::cin >> l >> r >> x >> y >> k;

    solve(l, r, x, y, k);

    return 0;
}

