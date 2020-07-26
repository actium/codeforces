#include <algorithm>
#include <iostream>
#include <string>

void no_answer()
{
    std::cout << "impossible" << '\n';
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::string& s, unsigned k)
{
    const size_t n = s.length();
    if (n < k)
        return no_answer();

    std::sort(s.begin(), s.end());

    const size_t c = std::unique(s.begin(), s.end()) - s.begin();
    answer(c < k ? k - c : 0);
}

int main()
{
    std::string s;
    std::cin >> s;

    unsigned k;
    std::cin >> k;

    solve(s, k);

    return 0;
}

