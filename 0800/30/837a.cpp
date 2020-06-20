#include <iostream>
#include <string>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    size_t v = 0, max_v = 0;
    for (const char c : s) {
        if (isupper(c))
            ++v;

        if (c == ' ')
            v = 0;

        max_v = std::max(max_v, v);
    }

    answer(max_v);
}

int main()
{
    size_t n;
    std::cin >> n;
    std::cin.ignore();

    std::string s;
    std::getline(std::cin, s);

    solve(s);

    return 0;
}

