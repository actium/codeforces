#include <algorithm>
#include <iostream>
#include <set>

void answer(unsigned x11, unsigned x12, unsigned x21, unsigned x22)
{
    std::cout << x11 << ' ' << x12 << '\n';
    std::cout << x21 << ' ' << x22 << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

bool valid(unsigned a, unsigned b, unsigned c, unsigned d)
{
    const std::set<unsigned> s = { a, b, c, d };
    return s.size() == 4 && std::all_of(s.cbegin(), s.cend(), [](unsigned x) { return x >= 1 && x <= 9; });
}

void solve(unsigned r1, unsigned r2, unsigned c1, unsigned c2, unsigned d1, unsigned d2)
{
    for (unsigned x11 = 1; x11 <= 9; ++x11) {
        const unsigned x12 = r1 - x11;
        const unsigned x21 = c1 - x11;
        const unsigned x22 = r2 - x21;

        if (x11 + x22 == d1 && x21 + x12 == d2 && valid(x11, x12, x21, x22))
            return answer(x11, x12, x21, x22);
    }

    no_answer();
}

int main()
{
    unsigned r1, r2;
    std::cin >> r1 >> r2;

    unsigned c1, c2;
    std::cin >> c1 >> c2;

    unsigned d1, d2;
    std::cin >> d1 >> d2;

    solve(r1, r2, c1, c2, d1, d2);

    return 0;
}

