#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::string& s)
{
    unsigned k = 0, q = 0;
    for (const char c : s) {
        if (c == '(') {
            ++q;
        } else if (q > 0) {
            k += 2;
            --q;
        }
    }

    answer(k);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
