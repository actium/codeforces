#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    unsigned v = 0, k = 0;
    for (const char c : s) {
        if (c == '0') {
            v = v * 10 + k;
            k = 0;
        } else {
            ++k;
        }
    }

    answer(v * 10 + k);
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

