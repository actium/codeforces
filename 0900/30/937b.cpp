#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned p, unsigned y)
{
    const auto test = [p](unsigned x) {
        for (unsigned i = 2; i <= p && i * i <= x; ++i) {
            if (x % i == 0)
                return false;
        }
        return x > p;
    };

    while (y > p && !test(y))
        --y;

    if (test(y))
        return answer(y);

    no_answer();
}

int main()
{
    unsigned p, y;
    std::cin >> p >> y;

    solve(p, y);

    return 0;
}
