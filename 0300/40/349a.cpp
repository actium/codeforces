#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    size_t f[2] = {};
    bool solvable = true;
    for (size_t i = 0; i < n; ++i) {
        size_t x;
        std::cin >> x;

        switch (x) {
            case 25:
                ++f[0];
                break;

            case 50:
                if (f[0] == 0) {
                    solvable = false;
                } else {
                    ++f[1];
                    --f[0];
                }
                break;

            case 100:
                if (f[0] == 0 || f[0] / 3 + f[1] == 0) {
                    solvable = false;
                } else if (f[1] > 0) {
                    --f[1];
                    --f[0];
                } else {
                    f[0] -= 3;
                }
                break;
        }
    }

    answer(solvable);

    return 0;
}

