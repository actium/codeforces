#include <array>
#include <iostream>
#include <string>

void answer(const std::array<std::string, 6>& v)
{
    for (const std::string& x : v)
        std::cout << x << '\n';
}

void solve(unsigned k)
{
    std::array<std::string, 6> s;
    s[0] = "+------------------------+";
    s[1] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)";
    s[2] = "|#.#.#.#.#.#.#.#.#.#.#.|.|";
    s[3] = "|#.......................|";
    s[4] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)";
    s[5] = "+------------------------+";

    for (unsigned i = 1; i < 5 && k > 0; ++i) {
        s[i][1] = 'O';
        --k;
    }

    for (unsigned j = 3; k > 0; j += 2) {
        for (unsigned p : { 1, 2, 4 }) {
            if (k > 0) {
                s[p][j] = 'O';
                --k;
            }
        }
    }

    answer(s);
}

int main()
{
    unsigned k;
    std::cin >> k;

    solve(k);

    return 0;
}

