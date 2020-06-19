#include <iostream>
#include <map>
#include <string>

int main()
{
    size_t n;
    std::cin >> n;

    std::map<std::string, std::string> stones = {
        { "purple", "Power" },
        { "green", "Time" },
        { "blue", "Space" },
        { "orange", "Soul" },
        { "red", "Reality" },
        { "yellow", "Mind" },
    };

    for (size_t i = 0; i < n; ++i) {
        std::string color;
        std::cin >> color;

        stones.erase(color);
    }

    std::cout << stones.size() << '\n';
    for (const auto& stone : stones)
        std::cout << stone.second << '\n';

    return 0;
}

