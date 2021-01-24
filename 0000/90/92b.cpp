#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::string& s)
{
    unsigned k = 0, c = 0;
    while (s.length() > 1) {
        if (s.back() == '1') {
            k += 2 - c;
            c = 1;
        } else {
            k += 1 + c;
        }
        s.pop_back();
    }

    answer(k + c);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

