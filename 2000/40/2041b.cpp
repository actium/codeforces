#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned count(unsigned u, unsigned v)
{
    unsigned s = 0, d = 1, k = 0;
    while (s < u) {
        s += d++;
        ++k;
    }

    const unsigned x = s - u;
    if (v < x)
        return k - 1;

    v -= x;
    for (s = 0; s + d <= v; s += d++)
        ++k;

    return k;
}

void solve(unsigned w, unsigned b)
{
    answer(std::max(count(w, b), count(b, w)));
}

void test_case()
{
    unsigned w, b;
    std::cin >> w >> b;

    solve(w, b);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
