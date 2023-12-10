#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned a, unsigned b, unsigned xk, unsigned yk, unsigned xq, unsigned yq)
{
    const auto check = [=](unsigned x, unsigned y) {
        for (const unsigned dx : { -a, +a }) {
            for (const unsigned dy : { -b, +b }) {
                if (x + dx == xq && y + dy == yq)
                    return 1;

                if (a != b && x + dy == xq && y + dx == yq)
                    return 1;
            }
        }
        return 0;
    };

    unsigned k = 0;
    for (const unsigned dx : { -a, +a }) {
        for (const unsigned dy : { -b, +b }) {
            k += check(xk + dx, yk + dy);

            if (a != b)
                k += check(xk + dy, yk + dx);
        }
    }

    answer(k);
}

void test_case()
{
    unsigned a, b;
    std::cin >> a >> b;

    unsigned xk, yk;
    std::cin >> xk >> yk;

    unsigned xq, yq;
    std::cin >> xq >> yq;

    solve(a, b, xk, yk, xq, yq);
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
