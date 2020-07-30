#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::string& n)
{
    unsigned k = 0;
    while (n.length() > 1) {
        ++k;

        unsigned s = 0;
        for (const char c : n)
            s += c - '0';

        n = std::to_string(s);
    }

    answer(k);
}

int main()
{
    std::string n;
    std::cin >> n;

    solve(n);

    return 0;
}

