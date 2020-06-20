#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n, m;
    std::cin >> n >> m;

    size_t f[2] = {};
    for (size_t i = 0; i < n; ++i) {
        int a;
        std::cin >> a;

        ++f[a != -1];
    }

    for (size_t i = 0; i < m; ++i) {
        size_t l, r;
        std::cin >> l >> r;

        const size_t k = r - l + 1;
        if (k % 2 == 1 || std::min(f[0], f[1]) < k/2) {
            answer(0);
        } else {
            answer(1);
        }
    }

    return 0;
}

