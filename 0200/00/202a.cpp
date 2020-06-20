#include <algorithm>
#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    for (char c = 'z'; c >= 'a'; --c) {
        const size_t k = std::count(s.cbegin(), s.cend(), c);
        if (k > 0)
            return answer(std::string(k, c));
    }
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

