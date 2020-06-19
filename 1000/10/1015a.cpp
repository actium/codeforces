#include <bitset>
#include <iostream>

void answer(size_t m, const std::bitset<101>& v)
{
    const size_t k = m - v.count();
    std::cout << k << '\n';

    if (k > 0) {
        const char* separator = "";
        for (size_t i = 1; i <= m; ++i) {
            if (v.test(i))
                continue;

            std::cout << separator << i;
            separator = " ";
        }
        std::cout << '\n';
    }
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::bitset<101> points;
    for (size_t i = 0; i < n; ++i) {
        unsigned l, r;
        std::cin >> l >> r;

        while (l <= r)
            points.set(l++);
    }

    answer(m, points);

    return 0;
}

