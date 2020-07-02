#include <array>
#include <iostream>
#include <string>

void answer(size_t v)
{
    constexpr const char* s[3] = { "Draw", "White", "Black" };
    std::cout << s[v] << '\n';
}

void solve(const std::array<std::string, 8>& board)
{
    size_t w[2] = {};
    for (const auto& row : board) {
        for (const char c : row) {
            switch (c) {
                case 'Q': w[0] += 9; break;
                case 'R': w[0] += 5; break;
                case 'B': w[0] += 3; break;
                case 'N': w[0] += 3; break;
                case 'P': w[0] += 1; break;
                case 'q': w[1] += 9; break;
                case 'r': w[1] += 5; break;
                case 'b': w[1] += 3; break;
                case 'n': w[1] += 3; break;
                case 'p': w[1] += 1; break;
            }
        }
    }

    if (w[0] == w[1])
        answer(0);
    else
        answer(1 + (w[1] > w[0]));
}

int main()
{
    std::array<std::string, 8> board;
    for (std::string& s : board)
        std::cin >> s;

    solve(board);

    return 0;
}

