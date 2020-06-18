#include <iostream>
#include <string>

size_t index(char type)
{
    return type - 'A';
}

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const size_t f[26])
{
    answer(f[index('T')] * 4 + f[index('C')] * 6 + f[index('O')] * 8 + f[index('D')] * 12 + f[index('I')] * 20);
}

int main()
{
    size_t n;
    std::cin >> n;

    size_t f[26] = {};
    for (size_t i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;

        ++f[index(s[0])];
    }

    solve(f);

    return 0;
}

