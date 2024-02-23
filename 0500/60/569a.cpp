#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned t, unsigned s, unsigned q)
{
    unsigned k = 0;
    while (s < t) {
        s *= q;
        ++k;
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned t, s, q;
    std::cin >> t >> s >> q;

    solve(t, s, q);

    return 0;
}
