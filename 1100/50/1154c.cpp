#include <algorithm>
#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned count(unsigned a, unsigned b, unsigned c)
{
    const unsigned w = std::min({ a / 3, b / 2, c / 2 });

    unsigned k = 7 * w;

    const auto extra = [&k](unsigned& x) {
        if (x-- == 0)
            return false;

        ++k;
        return true;
    };

    a -= 3 * w;
    b -= 2 * w;
    c -= 2 * w;

    extra(a) && extra(b) && extra(c) && extra(a) && extra(c) && extra(b) && extra(a);

    return k;
}

void solve(unsigned a, unsigned b, unsigned c)
{
    unsigned k = 0;

    k = std::max(k, count(a + 0, b + 0, c + 0) - 0);
    k = std::max(k, count(a + 1, b + 0, c + 0) - 1);
    k = std::max(k, count(a + 1, b + 1, c + 0) - 2);
    k = std::max(k, count(a + 1, b + 1, c + 1) - 3);
    k = std::max(k, count(a + 2, b + 1, c + 1) - 4);
    k = std::max(k, count(a + 2, b + 1, c + 2) - 5);
    k = std::max(k, count(a + 2, b + 2, c + 2) - 6);

    answer(k);
}

int main()
{
    unsigned a, b, c;
    std::cin >> a >> b >> c;

    solve(a, b, c);

    return 0;
}
