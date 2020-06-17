#include <iostream>
#include <string>

int execute(const std::string& statement, int x)
{
    for (const char c : statement) {
        if (c == '+')
            return ++x;

        if (c == '-')
            return --x;
    }
    return x;
}

void answer(int v)
{
    std::cout << v << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    int x = 0;
    for (size_t i = 0; i < n; ++i) {
        std::string statement;
        std::cin >> statement;

        x = execute(statement, x);
    }

    answer(x);

    return 0;
}

