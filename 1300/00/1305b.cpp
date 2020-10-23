#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<size_t>& v)
{
    if (!v.empty())
        std::cout << 1 << '\n';

    std::cout << v.size() << '\n';

    const char *separator = "";
    for (const size_t x : v)
    {
        std::cout << separator << 1 + x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::vector<size_t> x;
    for (size_t i = 0, j = n-1; i < j; ) {
        if (s[i] != '(') {
            ++i;
            continue;
        }
        if (s[j] != ')') {
            --j;
            continue;
        }

        x.push_back(i++);
        x.push_back(j--);
    }

    std::sort(x.begin(), x.end());

    answer(x);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

