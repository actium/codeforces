#include <iostream>
#include <string>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::string& stones)
{
    size_t count = 0;

    char last_stone = ' ';
    for (const char stone : stones) {
        if (stone == last_stone)
            ++count;

        last_stone = stone;
    }

    answer(count);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string stones;
    std::cin >> stones;

    solve(stones);

    return 0;
}

