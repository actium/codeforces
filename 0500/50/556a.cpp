#include <iostream>
#include <string>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    size_t f[2] = {};
    for (const char c : s) {
        ++f[c - '0'];
    }

    answer(f[0] + f[1] - 2 * std::min(f[0], f[1]));
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

