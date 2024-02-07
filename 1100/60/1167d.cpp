#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    std::string t = "1", c;
    for (const char x : s) {
        if (x == '(') {
            t.push_back(t.back() ^ 1);
            c.push_back(t.back());
        } else {
            c.push_back(t.back());
            t.pop_back();
        }
    }

    answer(c);
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
