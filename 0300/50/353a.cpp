#include <iostream>

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(const unsigned sums[2], bool solvable)
{
    if (sums[0] % 2 == 0 && sums[1] % 2 == 0)
        return answer(0);

    if (sums[0] % 2 != sums[1] % 2 || !solvable)
        return answer(-1);

    answer(1);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned sums[2] = {};
    bool solvable = false;
    for (size_t i = 0; i < n; ++i) {
        unsigned x, y;
        std::cin >> x >> y;

        sums[0] += x;
        sums[1] += y;

        if (x % 2 != y % 2)
            solvable = true;
    }

    solve(sums, solvable);

    return 0;
}

