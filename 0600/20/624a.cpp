#include <iostream>

void answer(double v)
{
    std::cout << std::fixed << v << '\n';
}

void solve(size_t d, size_t w, size_t v1, size_t v2)
{
    answer(double(w - d) / (v1 + v2));
}

int main()
{
    size_t d, w, v1, v2;
    std::cin >> d >> w >> v1 >> v2;

    solve(d, w, v1, v2);

    return 0;
}

