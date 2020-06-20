#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    size_t c = 0;
    for (size_t i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;

        c += x < 0;
    }

    answer(c < 2 || n - c < 2);

    return 0;
}

