#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& p)
{
    constexpr unsigned M = 1000003;

    unsigned s = 0;
    for (const char c : p) {
        unsigned k = 7;
        switch (c) {
            case ']': ++k;
            case '[': ++k;
            case ',': ++k;
            case '.': ++k;
            case '-': ++k;
            case '+': ++k;
            case '<': ++k;
            case '>': ++k;
        }

        s = (s << 4 | k) % M;
    }

    answer(s);
}

int main()
{
    std::string p;
    std::cin >> p;

    solve(p);

    return 0;
}

