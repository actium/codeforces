#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    std::string t(10, '0');

    for (const char e : s) {
        if (e == 'L') {
            const size_t p = t.find('0');
            //assert(p != std::string::npos);
            t[p] = '1';
            continue;
        }
        if (e == 'R') {
            const size_t p = t.rfind('0');
            //assert(p != std::string::npos);
            t[p] = '1';
            continue;
        }

        t[e - '0'] = '0';
    }

    answer(t);
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

