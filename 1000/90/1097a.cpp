#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

int main()
{
    std::string flop;
    std::cin >> flop;

    bool possible = false;
    for (size_t i = 0; i < 5; ++i) {
        std::string card;
        std::cin >> card;

        if (card[0] == flop[0] || card[1] == flop[1])
            possible = true;
    }

    answer(possible);

    return 0;
}

