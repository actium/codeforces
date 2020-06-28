#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string rows[4])
{
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            const size_t difference = (rows[i][j] != rows[i][j+1]) + (rows[i][j] != rows[i+1][j]) + (rows[i][j] != rows[i+1][j+1]);
            if (difference != 2)
                return answer(true);
        }
    }

    answer(false);
}

int main()
{
    std::string rows[4];
    for (size_t i = 0; i < 4; ++i)
        std::cin >> rows[i];

    solve(rows);

    return 0;
}

