#include <iostream>
#include <string>

void solve(const std::string& s)
{
    const size_t n = s.length();

    for (size_t i = 0; i < n; ++i) {
        std::cout << s[i];

        if (i % 2 == 1 && i + 2 < n)
            std::cout << '-';
    }
    std::cout << '\n';
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

