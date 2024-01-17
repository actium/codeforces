#include <iostream>
#include <vector>

using integer = unsigned long long;

std::vector<integer> factorize(integer x)
{
    std::vector<integer> factors;
    for (integer i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            factors.push_back(i);
            factors.push_back(x / i);
        }
    }
    return factors;
}

void answer(int x, int y)
{
    std::cout << x << ' ' << y << '\n';
}

void no_answer()
{
    std::cout << -1 << ' ' << -1 << '\n';
}

void solve(unsigned a, unsigned b, unsigned c, unsigned d)
{
    const integer u = 1, ab = u * a * b, cd = u * c * d;

    if (2 * a <= c && 2 * b <= d)
        return answer(2 * a, 2 * b);

    for (const integer f1 : factorize(a)) {
        for (const integer f2 : factorize(b)) {
            for (const integer f : { f1, f2, f1 * f2 }) {
                if (f > a && f <= c) {
                    const integer g = ab / f, y = d / g * g;
                    if (y > b)
                        return answer(f, y);
                }
                if (f > b && f <= d) {
                    const integer g = ab / f, x = c / g * g;
                    if (x > a)
                        return answer(x, f);
                }
            }
        }
    }

    no_answer();
}

void test_case()
{
    unsigned a, b, c, d;
    std::cin >> a >> b >> c >> d;

    solve(a, b, c, d);
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