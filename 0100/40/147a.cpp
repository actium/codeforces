#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    std::string t;
    for (const char c : s) {
        switch (c) {
            case '.': case ',': case '!': case '?':
                while (t.back() == ' ')
                    t.pop_back();

                t.push_back(c);
                t.push_back(' ');

            case ' ':
                if (t.back() == ' ')
                    break;

            default:
                t.push_back(c);
        }
    }

    answer(t);
}

int main()
{
    std::string s;
    std::getline(std::cin, s);

    solve(s);

    return 0;
}

