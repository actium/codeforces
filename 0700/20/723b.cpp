#include <iostream>
#include <string>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::string& s)
{
    unsigned l = 0, k = 0;

    unsigned b = 0, c = 0;
    for (const char x : s) {
        if (x != '_' && x != '(' && x != ')') {
            if (++c > l && b == 0)
                l = c;
        } else {
            if (c > 0 && b == 1)
                ++k;

            if (x != '_')
                b = (x == '(');

            c = 0;
        }
    }

    answer(l, k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    s.push_back('_');
    solve(s);

    return 0;
}

