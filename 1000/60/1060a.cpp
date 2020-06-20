#include <algorithm>
#include <iostream>
#include <string>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t k = std::count(s.cbegin(), s.cend(), '8');

    answer(std::min(s.length() / 11, k));
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

