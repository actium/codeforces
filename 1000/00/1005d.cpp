#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    unsigned k = 0, f[3] = {};
    for (const char c : s) {
        switch ((c - '0') % 3) {
            case 0:
                ++f[0];
                break;

            case 1:
                f[0] += (++f[1] == 3 || f[2] != 0);
                break;

            case 2:
                f[0] += (++f[2] == 3 || f[1] != 0);
                break;
        }

        if (f[0] != 0) {
            f[0] = f[1] = f[2] = 0;
            ++k;
        }
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
