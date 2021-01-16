#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::string t;
    for (size_t i = 0, c = 0; i < n; ++i) {
        if (i > 0 && i + 3 < n && s[i] == 'd' && s[i+1] == 'o' && s[i+2] == 't') {
            t.push_back('.');
            i += 2;
            continue;
        }
        if (i > 0 && i + 2 < n && c == 0 && s[i] == 'a' && s[i+1] == 't') {
            t.push_back('@');
            c = ++i;
            continue;
        }
        t.push_back(s[i]);
    }

    answer(t);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

