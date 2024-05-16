#include <iostream>

#include <cmath>

void answer(int x1, int y1, int x2, int y2)
{
    std::cout << "YES" << '\n';
    std::cout << 0 << ' ' << 0 << '\n';
    std::cout << x1 << ' ' << y1 << '\n';
    std::cout << x2 << ' ' << y2 << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(unsigned a, unsigned b)
{
    for (unsigned x1 = 1; x1 < a; ++x1) {
        const unsigned y1 = sqrt(a * a - x1 * x1);
        if (x1 * x1 + y1 * y1 != a * a)
            continue;

        const unsigned x2 = y1 * b / a, y2 = x1 * b / a;
        if (y2 != y1 && x2 * x2 + y2 * y2 == b * b)
            return answer(x1, y1, -x2, y2);
    }

    no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}
