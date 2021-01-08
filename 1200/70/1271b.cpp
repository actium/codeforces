#include <iostream>
#include <string>
#include <vector>

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(const std::vector<unsigned>& v)
{
    std::cout << v.size();

    const char* separator = "\n";
    for (const size_t x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::vector<unsigned> p;
    const auto check = [&](char c) {
        p.clear();

        char x = s[0];
        for (size_t i = 1; i < n; ++i) {
            if (x == c) {
                x = s[i];
            } else {
                p.push_back(i);
                x = 'W' + 'B' - s[i];
            }
        }

        return x == c;
    };

    if (check('B') || check('W'))
        return answer(p);

    no_answer();
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

