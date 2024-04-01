#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    for (char c = 'z'; c >= 'a'; --c) {
        for (size_t x = s.find(c); x != std::string::npos; ) {
            if (x != 0 && s[x-1] + 1 == c) {
                s.erase(x, 1);
                x = s.find(c);
                continue;
            }
            if (x + 1 < s.length() && s[x+1] + 1 == c) {
                s.erase(x, 1);
                x = s.find(c);
                continue;
            }
            x = s.find(c, x + 1);
        }
    }

    answer(n - s.length());
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
