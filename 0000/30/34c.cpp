#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    bool p[1002] = {};

    unsigned x = 0;
    for (const char c : s) {
        if (isdigit(c)) {
            x = x * 10 + c - '0';
        } else {
            p[x] = true;
            x = 0;
        }
    }

    std::string t;
    for (unsigned lb = 0, i = 1; i < 1002; ++i) {
        if (p[i] == p[i-1])
            continue;

        if (p[lb]) {
            t += std::to_string(lb);
            if (i > lb + 1) {
                t.push_back('-');
                t += std::to_string(i - 1);
            }
            t.push_back(',');
        }

        lb = i;
    }
    t.pop_back();

    answer(t);
}

int main()
{
    std::string s;
    std::cin >> s;
    s.push_back(' ');

    solve(s);

    return 0;
}

