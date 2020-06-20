#include <iostream>
#include <string>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    int d = 0;
    for (const char c : s) {
        if (c == '-')
            d = std::max(0, d - 1);
        else
            d = std::max(1, d + 1);
    }

    answer(d);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

