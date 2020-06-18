#include <iostream>
#include <string>

void answer(size_t v)
{
    std::cout << v << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    size_t count = 0;
    std::string last = "  ";
    for (size_t i = 0; i < n; ++i) {
        std::string current;
        std::cin >> current;

        if (current.front() != last.front()) {
            ++count;
            last = current;
        }
    }

    answer(count);

    return 0;
}

