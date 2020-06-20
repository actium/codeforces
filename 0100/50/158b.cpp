#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t f[5])
{
    const size_t min13 = std::min(f[1], f[3]);
    f[1] -= min13, f[3] -= min13, f[4] += min13;

    const size_t half1 = f[1] / 2;
    f[1] -= 2 * half1, f[2] += half1;

    const size_t half2 = f[2] / 2;
    f[2] -= 2 * half2, f[4] += half2;

    answer(f[4] + f[3] + std::max(f[2], f[1]));
}

int main()
{
    size_t n;
    std::cin >> n;

    size_t f[5] = {};
    for (size_t i = 0; i < n; ++i) {
        size_t s;
        std::cin >> s;

        ++f[s];
    }

    solve(f);

    return 0;
}

