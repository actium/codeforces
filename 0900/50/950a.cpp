#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t l, size_t r, size_t a)
{
    const size_t d = std::max(l, r) - std::min(l, r);
    if (d <= a) {
        a -= d;
        return answer(2 * (std::max(l, r) + a / 2));
    }

    answer(2 * (std::min(l, r) + a));
}

int main()
{
    size_t l, r, a;
    std::cin >> l >> r >> a;

    solve(l, r, a);

    return 0;
}

