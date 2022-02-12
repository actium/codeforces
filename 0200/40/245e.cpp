#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    unsigned i = 0, o = 0, q = 0;
    for (const char c : s) {
        if (c == '+') {
            o -= !!o;
            ++i;
        } else {
            i -= !!i;
            ++o;
        }
        q = std::max(q, i + o);
    }

    answer(q);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
