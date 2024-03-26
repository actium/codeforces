#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void overflow()
{
    std::cout << "OVERFLOW!!!" << '\n';
}

void solve(const std::vector<std::string>& p)
{
    using integer = unsigned long long;

    integer x = 0;

    std::vector<std::pair<integer, integer>> t;
    for (const std::string& s : p) {
        switch (s[0]) {
            case 'a':
                ++x;
                break;

            case 'f':
                t.emplace_back(x, std::stoull(s.substr(4)));
                x = 0;
                break;

            case 'e':
                x = t.back().first + x * t.back().second;
                t.pop_back();
                break;
        }

        if (x >= 1ull << 32)
            return overflow();
    }

    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t l;
    std::cin >> l >> std::ws;

    std::vector<std::string> p(l);
    for (size_t i = 0; i < l; ++i)
        std::getline(std::cin, p[i]);

    solve(p);

    return 0;
}
