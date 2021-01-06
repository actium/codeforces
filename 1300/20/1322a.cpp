#include <iostream>
#include <string>

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    int b = 0, k = 0;
    for (const char c : s) {
        if (c == '(') {
            k += (b++ < 0);
        } else {
            k += (--b < 0);
        }
    }

    answer(b == 0 ? k : -1);
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

