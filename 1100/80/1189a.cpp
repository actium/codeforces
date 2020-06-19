#include <algorithm>
#include <iostream>
#include <string>

void answer(size_t k, const std::string& s)
{
    std::cout << k << '\n';
    std::cout << s << '\n';
}

void answer(size_t k, const std::string& s, char z)
{
    std::cout << k << '\n';
    std::cout << s << ' ' << z << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    const size_t x = std::count(s.cbegin(), s.cend(), '0');
    const size_t y = n - x;

    if (x == y) {
        answer(2, s.substr(0, n-1), s.back());
    } else {
        answer(1, s);
    }
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

