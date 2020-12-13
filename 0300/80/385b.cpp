#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned k = 0;
    for (size_t i = 0, c = 0; i + 4 <= n; ++i) {
        if (s.substr(i, 4) == "bear")
            c = i + 1;

        k += c;
    }

    answer(k);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

