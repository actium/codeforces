#include <iostream>
#include <string>

void answer(unsigned r, unsigned b, unsigned y, unsigned g)
{
    std::cout << r << ' ' << b << ' ' << y << ' ' << g << '\n';
}

void solve(const std::string& s)
{
    const auto count = [&s](char c) {
        const size_t n = s.length();

        size_t i = 0;
        while (i < n && s[i] != c)
            ++i;

        unsigned k = 0;
        for (size_t j = i % 4; j < n; j += 4)
            k += (s[j] == '!');

        return k;
    };

    const unsigned r = count('R');
    const unsigned b = count('B');
    const unsigned y = count('Y');
    const unsigned g = count('G');

    answer(r, b, y, g);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

