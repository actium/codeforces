#include <iostream>
#include <string>

void answer(size_t k, const std::string& s)
{
    std::cout << k << '\n';
    std::cout << s << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    size_t count = 0;
    for (size_t i = 0; i < n; i += 2) {
        if (s[i] != s[i+1])
            continue;

        if (s[i] == 'a')
            s[i] = 'b';
        else
            s[i] = 'a';

        ++count;
    }

    answer(count, s);
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

