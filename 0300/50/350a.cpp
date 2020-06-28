#include <iostream>

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(unsigned min_a, unsigned max_a, unsigned min_b)
{
    if (min_b <= max_a)
        return answer(-1);

    if (2 * min_a >= min_b)
        return answer(-1);

    answer(std::max(max_a, 2 * min_a));
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    unsigned min_a = 101, max_a = 0;	// out of a range
    for (size_t i = 0; i < n; ++i) {
        unsigned a;
        std::cin >> a;

        min_a = std::min(min_a, a);
        max_a = std::max(max_a, a);
    }

    unsigned min_b = 101;	// out of b range
    for (size_t i = 0; i < m; ++i) {
        unsigned b;
        std::cin >> b;

        min_b = std::min(min_b, b);
    }

    solve(min_a, max_a, min_b);

    return 0;
}

