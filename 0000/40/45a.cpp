#include <iostream>
#include <string>

void answer(const char* v)
{
    std::cout << v << '\n';
}

void solve(const std::string& m, unsigned k)
{
    constexpr const char* s[12] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December",
    };

    size_t x = 0;
    while (m != s[x])
        ++x;

    answer(s[(x + k) % 12]);
}

int main()
{
    std::string m;
    std::cin >> m;

    unsigned k;
    std::cin >> k;

    solve(m, k);

    return 0;
}

