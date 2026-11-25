#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned x, unsigned y, const std::string& s)
{
    unsigned k = x + y;
    for (const char c : s) {
        if (x + y == 0)
            break;

        if (c == '+') {
            x -= (y++ == 0);
        } else {
            if (x == 0 || y > 1) {
                --y;
                ++x;
            } else {
                --x;
            }
        }

        k = std::max(k, x + y);
    }

    answer(k);
}

void test_case()
{
    unsigned x, y;
    std::cin >> x >> y;

    size_t m;
    std::cin >> m;

    std::string s;
    std::cin >> s;

    solve(x, y, s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
