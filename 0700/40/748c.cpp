#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& p)
{
    unsigned k = !p.empty();

    char h = ' ', v = ' ';
    for (const char c : p) {
        if (c == 'L' || c == 'R') {
            if (h == (c ^ 'L' ^ 'R')) {
                ++k;
                v = ' ';
            }
            h = c;
        } else {
            if (v == (c ^ 'U' ^ 'D')) {
                ++k;
                h = ' ';
            }
            v = c;
        }
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string p;
    std::cin >> p;

    solve(p);

    return 0;
}
