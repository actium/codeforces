#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned s, unsigned x1, unsigned x2, unsigned t1, unsigned t2, unsigned p, int d)
{
    if (x2 < x1) {
        x1 = s - x1;
        x2 = s - x2;
        p = s - p;
        d = -d;
    }

    const unsigned v2 = (x2 - x1) * t2;

    if (d < 0)
        return answer(std::min((p + x2) * t1, v2));

    if (p <= x1)
        return answer(std::min((x2 - p) * t1, v2));

    answer(std::min((2 * s - p + x2) * t1, v2));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned s, x1, x2;
    std::cin >> s >> x1 >> x2;

    unsigned t1, t2;
    std::cin >> t1 >> t2;

    unsigned p;
    std::cin >> p;

    int d;
    std::cin >> d;

    solve(s, x1, x2, t1, t2, p, d);

    return 0;
}
