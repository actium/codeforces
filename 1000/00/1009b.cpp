#include <algorithm>
#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned k = std::count(s.cbegin(), s.cend(), '1');

    std::string t;
    for (const char c : s) {
        if (c == '1')
            continue;

        if (c == '2' && k != 0) {
            t.append(k, '1');
            k = 0;
        }

        t.push_back(c);
    }

    answer(t + std::string(k, '1'));
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
