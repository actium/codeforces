#include <iostream>
#include <string>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    integer w = 0, c = 0, k = 0;
    for (size_t i = 1; i < n; ++i) {
        if (s[i] == 'v' && s[i-1] == 'v')
            k += c, ++w;

        if (s[i] == 'o')
            c += w;
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

