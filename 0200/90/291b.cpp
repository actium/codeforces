#include <iostream>
#include <string>

void solve(const std::string& s)
{
    bool b = true, q = false;
    for (const char c : s) {
        if (c == ' ' && !q) {
            if (!b) {
                std::cout << '>' << '\n';
                b = true;
            }
            continue;
        }

        if (b) {
            std::cout << '<';
            b = false;
        }

        if (c == '"') {
            q = !q;
        } else {
            std::cout << c;
        }
    }
}

int main()
{
    std::string s;
    std::getline(std::cin, s);

    solve(s + ' ');

    return 0;
}

