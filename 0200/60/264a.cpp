#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<size_t>& v)
{
    for (const size_t x : v)
        std::cout << 1+x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::vector<size_t> x, y;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == 'r')
            y.push_back(i);
        else
            x.push_back(i);
    }
    y.insert(y.end(), x.crbegin(), x.crend());

    answer(y);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

