#include <algorithm>
#include <array>
#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(std::array<unsigned, 4>& colors)
{
    std::sort(colors.begin(), colors.end());

    const auto it = std::unique(colors.begin(), colors.end());
    answer(std::distance(it, colors.end()));
}

int main()
{
    std::array<unsigned, 4> colors;
    for (size_t i = 0; i < 4; ++i)
        std::cin >> colors[i];

    solve(colors);

    return 0;
}

