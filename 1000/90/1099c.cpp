#include <algorithm>
#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void no_answer()
{
    std::cout << "Impossible" << '\n';
}

void solve(std::string& s, size_t k)
{
    unsigned m = std::count_if(s.begin(), s.end(), [](char c) { return c == '?' || c == '*'; });

    while (s.length() - m > k) {
        const size_t x = s.find_first_of("?*");
        if (x == std::string::npos)
            break;

        s.erase(x-1, 2);
        --m;
    }

    if (s.length() - m < k) {
        const size_t x = s.find('*');
        if (x != std::string::npos)
            s.replace(x, 1, k - (s.length() - m), s[x-1]);
    }

    s.erase(std::remove(s.begin(), s.end(), '?'), s.end());
    s.erase(std::remove(s.begin(), s.end(), '*'), s.end());

    answer(s.length() == k ? s : "Impossible");
}

int main()
{
    std::string s;
    std::cin >> s;

    size_t k;
    std::cin >> k;

    solve(s, k);

    return 0;
}

