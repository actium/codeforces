#include <algorithm>
#include <iostream>
#include <string>

void answer(unsigned v)
{
    constexpr const char* s[4] = { "fantasy", "forward", "backward", "both" };
    std::cout << s[v] << '\n';
}

void solve(std::string& s, const std::string& x, const std::string& y)
{
    const auto check = [&]() -> unsigned {
        const size_t p = s.find(x);
        return p != std::string::npos && s.find(y, p + x.length()) != std::string::npos;
    };

    const unsigned m = check();
    std::reverse(s.begin(), s.end());
    answer(m | check() << 1);
}

int main()
{
    std::string s, a, b;
    std::cin >> s >> a >> b;

    solve(s, a, b);

    return 0;
}

